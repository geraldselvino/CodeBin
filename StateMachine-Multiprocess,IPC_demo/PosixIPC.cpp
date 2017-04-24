/**********************************************************
* Copyright (c) 2017, Gerald Selvino
* <gerald.selvino@protonmail.com> All rights reserved.
*
* The class that contains the necessary routines to
* implement a cross platform POSIX multiprocess shared
* memory IPC state machine
***********************************************************/

#include "PosixIPC.h"
#include <fstream>
#include <sstream>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <iostream>
#include <signal.h>

PosixIPC::PosixIPC()
:sharedmemfd(0),
buffer(NULL),
buffersize(1024),
mutexsemaphore(NULL) {
}

PosixIPC::~PosixIPC() {
    cleanup();
    buffer = NULL;
    mutexsemaphore = NULL;
}

bool PosixIPC::init(pid_t pid) {
    if (pid == 0) { //Child process
        mutexsemaphore = sem_open(MUTEXSEMAPHORE_NAME, O_RDWR, 0, 0);
        sharedmemfd = shm_open(SHAREDMEMORY_NAME, O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    } else { //Parent process
        mutexsemaphore = sem_open(MUTEXSEMAPHORE_NAME, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO, 0);
        sharedmemfd = shm_open(SHAREDMEMORY_NAME, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    }

    if (mutexsemaphore == SEM_FAILED) {
        perror("sem_open failed");
        cleanup();      
        return false;
    }

    if (sharedmemfd == -1) {
        perror("shm_open failed");
        cleanup();
        return false;
    }

    if (ftruncate(sharedmemfd, buffersize) == -1) {
        perror ("ftruncate failed");
        cleanup();
        return false;
    }

    if (pid == 0) //Child process
        buffer = (char*) mmap(NULL, buffersize, PROT_READ | PROT_WRITE, MAP_SHARED, sharedmemfd, 0);
    else //Parent process
        buffer = (char*) mmap(NULL, buffersize, PROT_READ | PROT_WRITE, MAP_SHARED, sharedmemfd, 0);

    if (buffer < 0) {
        cleanup();
        return false;
    }

    if (sem_post(mutexsemaphore) == -1) {
        perror ("sem_post failed");
        cleanup();
        return false;
    }

    return true;
}

bool PosixIPC::readConfigurationFile(string const& confpath) {
    if (confpath.length() == 0){
        perror("Invalid configuration file");
        return false;
    }

    ifstream configfd;
    configfd.open(confpath, ifstream::in);
    string strline;
    /**
    * Reads the configuration file and
    * push the values to a vector
    * config file is in the form of STATE=EXPIRY_TIME
    * e.g.
    * ACTIVE=1
    * GUARD=2
    * STOP=3
    */ 
    while (getline(configfd, strline)) {
        size_t pos = strline.find("=");
        if (pos > 0) {
            State stateitem;
            stateitem.name = strline.substr(0, pos);
            stateitem.expirytime = atoi(strline.substr(pos + 1, strline.length() - pos).c_str());
            states.push_back(stateitem);
        }
    }
    return true;
}

bool PosixIPC::startLoop() {
    if (states.empty()) {
        perror("Configuration(states.conf) values are empty");
        return false;
    }
    uint32_t sequence = 1;
    uint16_t statesindex = 0;
    time_t ticksnow = time(NULL);
    bool writetobuffer = true;

    while(true) {
        time_t timediff = time(NULL) - ticksnow;
        if (timediff >= states[statesindex].expirytime) {
            ++sequence;
            writetobuffer = true;
            ticksnow = time(NULL);
            timediff = 0;
            if (statesindex == 2)
                statesindex = 0;
            else
                ++statesindex;
        }

        if (writetobuffer) {
            ostringstream concatstr;
            concatstr.clear();
            concatstr.str(string());

            uint32_t remainingtime = states[statesindex].expirytime - timediff;
            concatstr << states[statesindex].name << "," << remainingtime << "," << sequence;
            if (sem_wait (mutexsemaphore) == -1) { //Guard the writing with mutex semaphore
                perror ("sem_wait failed");
                cleanup();
                return false;
            }

            int size = snprintf(buffer, buffersize, concatstr.str().c_str()); //Write the states to the shared buffer
            if (size <= 0) {
                perror("writing to shared buffer failed");
                cleanup();
                return false;
            }

            if (sem_post(mutexsemaphore) == -1) { //Release the mutex semaphore
                perror ("sem_post failed");
                cleanup();
                return false;
            }
            writetobuffer = false;
        }

        nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
    }

    return true;
}

bool PosixIPC::readValues() {
    if (sem_wait (mutexsemaphore) == -1) { //Guard the buffer read
        perror ("sem_wait failed");
        cleanup();
        return false;
    }

    if (buffer != NULL) { //Read the buffer and put it to variables
        char* token;
        char* tokens[3];
        memset(tokens, 0, sizeof(tokens));
        token = strtok (buffer,",");
        uint16_t tkindex = 0;
        while (token != NULL) {
            tokens[tkindex] = token;
            token = strtok (NULL, ",");
            tkindex++;
        }
        currentstatus = tokens[0];
        timeremaining = tokens[1];
        currentsequence = tokens[2];
    }

    if (sem_post(mutexsemaphore) == -1) { //Release the mutex
        perror ("sem_post failed");
        cleanup();
        return false;
    }

    return true;
}

void PosixIPC::showConsole() {
    char code = '\0';
    cout << "[c]urrent state" << endl;
    cout << "[t]ime remaining" << endl;
    cout << "[s]equence number" << endl;
    cout << endl;

    cout << "Select what you want to display: ";
    cin >> code;
    if (!readValues())
        perror("Unable to read values from shared memory");

    switch(code) {
        cout << endl << endl;
        case 'c':
            cout << "The current STATE is: " << currentstatus << endl;
            break;
        case 't':
            cout << "The time remaining before the next state is: " << timeremaining << endl;
            break;
        case 's':
            cout << "The current sequence number is: " << currentsequence << endl;
            break;
    }
    
    kill(0, SIGINT);
}

void PosixIPC::cleanup() {
    if (buffer > 0)
        munmap(buffer, buffersize);

    if (sharedmemfd > 0) {
        close(sharedmemfd);
        shm_unlink(SHAREDMEMORY_NAME);
    }

    if (mutexsemaphore != SEM_FAILED) {
        sem_close(mutexsemaphore);
        sem_unlink(MUTEXSEMAPHORE_NAME);
    }
}
