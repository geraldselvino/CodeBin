StateMachine
==============
This a simple state machine that reads a config file (default is states.conf)
for states and its expiration time, it then start with the first entry in the 
config file as the initial state, changing states as the expiration time of the 
current state is reached. The user can then query the current state, time 
remaining before expiration, and current sequence. Illustrated in the table 
below is the flow of the state machine.

State  |Event              |Next state
-------|-------------------|----------
GUARD  |Guard time expired |ACTIVE   
ACTIVE |Active time expired|STOP     
STOP   |Stop time expired  |GUARD    

The configuration file is in format STATE=ExpiryTime. 1 line per entry/state  
example:  
   ACTIVE=1  
   GUARD=2  
   STOP=3  

A high level architecture diagram is found in StateMachine-architecture.pdf
 
Purpose
==============
This program illustrates cross platform code within POSIX systems, multi process
programming and highly optimal Inter Process Communication using shared memory.

Steps to test
==============
1. To test this program, you simply download the files into 1 directory
2. go to the directory using a terminal/shell
3. compile the program by typing "make"
4. run it with "./statemachine"
    
