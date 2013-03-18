/**********************************************
* Author: Gerald Selvino
* Description: Quick sort demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

int data[]={444,555,222,111,999,0,888,777,333,666};

void quicksort(int start, int end){
    if(start>=end)return;

    //For better pivot selection, compute the median instead
    int pivot = end;
    cout<<"\nPivot: "<<data[pivot];
    int i=start,j=end;

    while(i<j){
        while(data[i]<data[pivot])i++;
        while(data[j]>=data[pivot] && j>i)j--;

        if(i<j){
            int tmp = data[i];
            data[i]=data[j];
            data[j]=tmp;
            i++;

            cout<<endl;
            for(int a=0;a<10;a++){
                cout << data[a]<<" ";
            }
        }
    }

    if(i!=pivot){
        int tmp = data[pivot];
        data[pivot]=data[i];
        data[i] = tmp;

        cout<<endl;
        for(int a=0;a<10;a++){
            cout << data[a]<<" ";
        }
    }

    quicksort(start, i-1);
    quicksort(i+1, end);
}

int main()
{
    cout<<"Original:\n";
    for(int i=0; i<10; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    quicksort(0,9);

    cout<<endl<<endl;
    cout<<"sorted:\n";
    for(int i=0;i<10;i++){
        cout<<data[i]<<" ";
    }

    return 0;
}
