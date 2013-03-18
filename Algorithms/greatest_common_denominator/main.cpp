/**********************************************
* Author: Gerald Selvino
* Description: Find the greatest common denominator
*              between 2 numbers using Euclid's
*              algorithm demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "input 2 numbers, separated by spaces: ";
    int a,b;
    cin>>a>>b;
    cout<<endl;

    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int d;
    while((d=a%b)!=0){
        a=b;
        b=d;
    }

    cout<<"the GCD is: "<<b;

    return 0;
}
