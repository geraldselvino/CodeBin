/**********************************************************
* Copyright (c) 2017, Gerald Selvino 
* <gerald.selvino@protonmail.com> All rights reserved.
*
* The class that contains the necessary routines to  
* implement a cross platform POSIX multiprocess shared
* memory IPC state machine
***********************************************************/

#include <stdint.h>
#include <stdio.h>
#include <map>
#include <string>
#include <semaphore.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

 /**
 * defines the name of the IPC semaphore
 * and shared memory
 */      
#define MUTEXSEMAPHORE_NAME "/mutexsemaphore"
#define SHAREDMEMORY_NAME "/posix-sharedmemory"

using namespace std;

 /**
 * A structure to read the states and
 * its expiration time from the states.conf
 */ 
struct State {
    string name;
    uint32_t expirytime;
};

class PosixIPC {
public:
    PosixIPC();
    virtual ~PosixIPC();

    /**
    * @brief Initializes the shared memory
    * and semaphores needed by the process
    * @param pid - the process id of the process
    */ 
    bool init(pid_t pid);
    /**
    * @brief Reads the configuration file
    * and brings it to a vector structure
    * @param confpath - the path of the config file
    */ 
    bool readConfigurationFile(string const& confpath);
    /**
    * @brief Starts the state machine loop
    */ 
    bool startLoop();
    /**
    * @brief Shows the console, so the user
    * can query the states
    */ 
    void showConsole();

private:
    /**
    * @brief Release resources (e.g. shared mem and semaphore)
    */ 
    void cleanup();
    /**
    * @brief This method is used by showConsole() to query the
    * states values from the shared buffer
    */ 
    bool readValues();

private:
    string currentstatus;
    string currentsequence;
    string timeremaining;
    map<string, State> states; 
    string initialstate;

    int sharedmemfd;
    char* buffer;
    size_t buffersize;
    sem_t* mutexsemaphore;
};
