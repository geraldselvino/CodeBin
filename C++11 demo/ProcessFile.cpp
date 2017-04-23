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
#include "ProcessFile.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#define FILE_COUNT	10

bool ProcessFile::showWordFrequencies(string const& path) {
    if (path.length() == 0) {
        return false;
    }
    mPath = path;

    thread threads[FILE_COUNT]; //Use of c++ 11 threads i.e. std::threads
    for (uint32_t i = 0; i < FILE_COUNT; ++i) {
        threads[i] = spawnThread(i);
    }
    for (uint32_t i = 0; i < FILE_COUNT; ++i) {
        threads[i].join();
    }

    displayWordFrequencies();

    return true;
}

void ProcessFile::getWordFrequencies(uint16_t fileNo) {
    if (mPath.length() == 0)
        return;
    ifstream mFileHandle;

    ostringstream ss;
    ss.clear();
    ss.str(string());
    ss << mPath << "data_" << fileNo << ".txt";
    mFileHandle.open(ss.str().c_str(), std::ifstream::in);
    string strline;
    while (getline(mFileHandle, strline)) {
        std::lock_guard<std::mutex> guard(mWordMapMutex);
        if (mWordMap.find(strline) == mWordMap.end())
            mWordMap[strline] = 1;
        else
            ++mWordMap[strline];
    }
}

void ProcessFile::displayWordFrequencies() {
    if (mWordMap.size() == 0)
        return;

    vector<pair<string, uint32_t> > wordlist;
    for (auto iterator = mWordMap.begin(); iterator != mWordMap.end(); ++iterator) {
        wordlist.push_back(*iterator);
    }

    sort(wordlist.begin(), wordlist.end(), [=](pair<string, uint32_t>& a, pair<string, uint32_t>& b) { //Use of lambda
        return a.second > b.second;
    }
    );

    for (auto printItr = wordlist.begin(); printItr != wordlist.end(); ++printItr) {
        if (printItr->second > 1)
            cout << printItr->second << "\t" << printItr->first << endl;
    }
}

thread ProcessFile::spawnThread(uint16_t fileNo) {
    return thread([=]{getWordFrequencies(fileNo);}); //Use of lambda
}