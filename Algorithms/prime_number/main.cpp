/**********************************************
* Author: Gerald Selvino
* Description: Determine a number if it's a 
*              prime number demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int n;
    cin>>n;
    bool isprime = true;

    for(int j=2; j<n; j++){
        if(n%j==0){
            isprime = false;
            break;
        }
    }

    if(isprime)cout<<"\nprime number";
    else cout<<"composite number";

    return 0;
}
