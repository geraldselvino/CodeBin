Word frequency counter
======================
A simple program that counts the number of frequencies that each word appears
in a number of text files and display those words with frequencies higher than 
or equal to 2. The name of text files by default is "data_x.txt" where "x" is 
the file number. e.g "data_1.txt, data_2.txt". The number of text files to be 
searched by the program can be changed through the FILE_COUNT macro in the 
ProcessFile class, by default it is 10 i.e. "data_1.txt" - "data_10.txt".

**Sample text file format**  
*data_1.txt*  
rose  
ivy  
crimson  
tide  
cresantimum  
sunflower  
tulips  

*data_2.txt*  
amber  
sampaguita  
mulberry  
rose  
tide  
strawberry  
rose  
red   

**Sample output**  
3   rose  
2   tide  

Requirement
===========
c++11 compliant compiler  

Purpose
=======
The program is a good illustration of practical usage of a few important C++11
additions / features like std::threads, std::mutex, lambda, C++11 initializers,
defaulted and deleted (ctor, dtor, copy ctor, assignment oprtr)

