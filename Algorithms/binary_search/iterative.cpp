/**********************************************
* Author: Gerald Selvino
* Description: Binary Search demo, iterative version
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

int main()
{
    struct sdata{
        int index;
        string message;
    };

    sdata data[]={{1,"gerald"},{2,"selvino"},{3,"jennifer"},{4,"lawrence"},{5,"anne"},{6,"hathaway"},
                  {7,"jack"},{8,"hughes"},{9,"amanda"}};

    int val = 6;
    int size = 8;
    int head=0,tail=size;
    int i;

    do{
        i=((head+tail)/2);
        if(val>data[i].index){
            head=i+1;
        }
        else if(val<data[i].index){
            tail=i-1;
        }
    }while(data[i].index!=val);

    cout<<endl<<data[i].message;

    return 0;
}
