Some notes:
==============
The configuration file is in format STATE=ExpiryTime. 1 line per entry/state  
example:  
   ACTIVE=1  
   GUARD=2  
   STOP=3  

Steps to test:
==============
1. To test this program, you simply extract the tarball to a directory  
    tar -xvf Irdeto-POSIX-IPC-test.tar  
2. go to the extraction directory  
    cd Irdeto-POSIX-IPC-test  
3. compile the program  
    make  
4. run it  
    ./posixipc  
    
