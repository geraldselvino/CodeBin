/**********************************************************
* Copyright (c) 2017, Gerald Selvino 
* <gerald.selvino@protonmail.com> All rights reserved.
*
* The main application entry point for PosixIPC
* state machine
***********************************************************/

#include "PosixIPC.h"
#include <iostream>

int main(int argc, char **argv)
{
    pid_t forkedpid = 0;  
    PosixIPC statemachine;

    forkedpid = fork();

    if (!statemachine.init(forkedpid)) {
        perror("Initialization failed");
        return 1;
    }

    if (forkedpid < 0) {
        perror("Call to fork() failed");
        return 1;
        
    } else if (forkedpid == 0) { //Child process		
        statemachine.showConsole();
        
    } else { //Parent process
        if (!statemachine.readConfigurationFile("./states.conf")) {
            perror("Unable to read configuration file");
            return 1;
        }
        if (!statemachine.startLoop()) {
            perror("Failed to start the loop");
            return 1;
        }
    }
 
    return 0;
}
