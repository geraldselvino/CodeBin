/**********************************************
* Author: Gerald Selvino
* Description: A function that converts a number
*              string to an integer, just like
*              atoi()
* Language: C++
***********************************************/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    cout << "enter a numeral string: ";
    char stor[20];
    cin>>stor;
    cout<<endl;

    int result=0;

    for(int i=0; i<strlen(stor); i++){
        if(stor[i]>='0' && stor[i]<='9'){
            result = result*10 + (stor[i]-'0');
        }
    }

    cout<<result;
    return 0;
}
