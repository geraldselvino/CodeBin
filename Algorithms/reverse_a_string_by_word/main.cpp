/**********************************************
* Author: Gerald Selvino
* Description: Reverse a string by word demo
* Language: C++
***********************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    cout << "Enter a string: ";
    char input[50];
    gets(input);
    cout<<endl;

    for(int b=0,e=strlen(input)-1; b<e; b++,e--){
        char tmp = input[b];
        input[b] = input[e];
        input[e] = tmp;
    }

    int start = 0;
    int end = 0;

    for(int i=0; i<=strlen(input); i++){

        if(i==0)start = i;
        if(start>end && input[start]==' '){
            start++;
            continue;
        }
        if(input[i]!=' '&&i<strlen(input))continue;
        else end = i;

        if(end>start){
            for(int a=start,b=end-1; a<b; a++,b--){
                char tmp = input[a];
                input[a] = input[b];
                input[b] = tmp;
            }
            start = end+1;
        }
    }

    for(int i=0; i<strlen(input); i++){
        cout<<input[i];
    }

    return 0;
}
