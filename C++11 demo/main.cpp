/**********************************************************
* Copyright (c) 2017, Gerald Selvino
* <gerald.selvino@protonmail.com> All rights reserved.
*
* A simple driver app for the ProcessFile class
***********************************************************/
#include "ProcessFile.h"

int main(int argc, char** argv) {
    ProcessFile fileProcessor;
    if (!fileProcessor.showWordFrequencies()) {
        cout << "There is an error counting the word frequencies";
        return -1;
    }

    return 0;
}