/**********************************************
* Author: Gerald Selvino
* Date: January 11, 2013
* Description: Spotify Cat vs. Dog problem
* Problem ID: catvsdog
* Language: C++
***********************************************/

#include <iostream>
#include <map>
#include <string.h>

using namespace std;

struct catDogStruct
{
    catDogStruct()
    {
        petKeep = 0;
        petThrow = 0;
    }

    int petKeep;
    int petThrow;
};

int main()
{
    int numTestcase;
    int nCats;
    int nDogs;
    int nVoters;
    string petKeep;
    string petThrow;
    map<string,catDogStruct> dataMap;
    map<string,catDogStruct>::iterator iterDataMap;

    cout<<"Enter number of testcases: ";
    cin>>numTestcase;
    cout<<endl;
    for(int i=0; i<numTestcase; i++)
    {
        dataMap.clear();

        cout<<"\n\nInput Cats, Dogs, Voters: ";
        cin>>nCats>>nDogs>>nVoters;
        cout<<endl;
        for(int j=0; j<nVoters; j++)
        {
            cout<<"Input what to Keep and Throw: ";
            cin>>petKeep>>petThrow;
            dataMap[petKeep].petKeep++;
            dataMap[petThrow].petThrow++;
        }

        int maxSatisfiedVoters = 0;

        for(iterDataMap=dataMap.begin(); iterDataMap!=dataMap.end(); iterDataMap++)
        {
            int keepThrowDiff = iterDataMap->second.petKeep - iterDataMap->second.petThrow;
            if(keepThrowDiff>0 && keepThrowDiff>maxSatisfiedVoters)
            {
                maxSatisfiedVoters = iterDataMap->second.petKeep;
            }
        }

        if(maxSatisfiedVoters> 0)
        {
            cout<<"\nMax satisfied voters: "<<maxSatisfiedVoters;
        }
        else
        {
            cout<<"\nMax satisfied voters: 1";
        }
    }

    return 0;
}
