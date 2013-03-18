/**********************************************
* Author: Gerald Selvino
* Description: Iterative fibonacci sequence demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter n: ";
    int n;
    cin>>n;
    cout<<endl;

    int prev = 0;
    int current = 1;
    int sum = 0;

    for(int i=0; i<n; i++){
        cout<<current<< " ";
        sum = prev + current;
        prev = current;
        current = sum;
    }

    return 0;
}
