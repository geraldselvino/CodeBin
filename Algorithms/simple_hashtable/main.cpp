/**********************************************
* Author: Gerald Selvino
* Description: Simple hashing function using
*              modulo demo
* Language: C++
***********************************************/
#include <iostream>
#define HASHSIZE 10

using namespace std;

struct hashstruct{
    int key;
    string data;
};

hashstruct hashtable[HASHSIZE];

int getIndex(int key){
    return key%HASHSIZE;
}

void insert(int key, string data){
    hashtable[getIndex(key)].key=key;
    hashtable[getIndex(key)].data=data;
}

int main()
{
    insert(2, "gerald");
    insert(3, "selvino");
    insert(4, "jennifer");

    cout<<"data in key 4 is: "<<hashtable[getIndex(4)].data;

    return 0;
}
