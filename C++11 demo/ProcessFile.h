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
    ProcessFile() = default;
    ~ProcessFile() = default;

    bool showWordFrequencies(string const& path = "./");

protected:
    void getWordFrequencies(uint16_t fileNo);
    void displayWordFrequencies();

private:
    thread spawnThread(uint16_t fileNo);

private:
    map<string, uint32_t> mWordMap;
    string mPath = "";
    mutex mWordMapMutex;
};