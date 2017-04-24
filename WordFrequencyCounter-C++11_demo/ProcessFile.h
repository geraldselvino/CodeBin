/**********************************************************
* Copyright (c) 2017, Gerald Selvino
* <gerald.selvino@protonmail.com> All rights reserved.
*
* The class that contains all methods to count the
* frequencies of each word listed in a number of text
* files. The number of text files to read is defined
* in the FILE_COUNT define. By default this value is 10,
* so the program will read all text files with names
* "data_1.txt - data_10.txt". The name of the text files
* are in that format i.e. "data_<n>.txt", this can be
* changed from the code in getWordFrequencies method
***********************************************************/
#pragma once

#include <thread>
#include <map>
#include <string>
#include <stdint.h>
#include <iostream>
#include <mutex>
using namespace std;

class ProcessFile {
public:
    ProcessFile() = default; //Use of defaulted constructor
    virtual ~ProcessFile() = default; //Use of defaulted destructor
    /**
    * In the same way as the default keyword is the delete keyword
    * which is useful in preventing a class to be copied. An
    * example of that is deleted default copy ctor and
    * assignment operator.
    * e.g. 
    * ProcessFile(const ProcessFile& other) = delete;
	* ProcessFile& operator = (const ProcessFile& other) = delete;
    */

    /**
    * @brief The main method to be called by the callee, it spawns the threads
    * and displays the word frequencies
    * @param path - The directory where to read the text files
    */
    bool showWordFrequencies(string const& path = "./");

protected:
    /**
    * @brief Reads the text file and count the word frequencies in a
    * std::map structure
    * @param fileNo - The current thread number which is associated
    * to the file number. This means 1 thread will process 1 text file,
    * so 10 text files will be handle by 10 threads simultaneously
    */
    void getWordFrequencies(uint16_t fileNo);
    /**
    * @brief Displays the frequencies of each word from the text files
    * with frequency higher than 2
    */
    void displayWordFrequencies();

private:
    /**
    * @brief Thread spawner
    */
    thread spawnThread(uint16_t fileNo);

private:
    map<string, uint32_t> mWordMap;
    string mPath = ""; //Use of c++ 11 initializers (though this is not necessary for std::string)
    mutex mWordMapMutex;
};