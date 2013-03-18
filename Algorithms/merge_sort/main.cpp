/**********************************************
* Author: Gerald Selvino
* Description: Merge sort demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

int data[]={5,6,7,1,4,3,2,9,8};
int temp[9];

void merge(int left, int center, int right);

void mergesort(int left, int right){
    if(right>left){
        int center = (right+left)/2;
        mergesort(left, center);
        mergesort(center+1, right);
        merge(left, center+1, right);
    }
}

void merge(int left, int center, int right){
    int templeft = left;
    int origcenter = center;
    int origleft = left;
    int origright = right;

    while(left<=origcenter-1 && center<=right){
        if(data[left]>=data[center]){
            temp[templeft] = data[center];
            center++;
            templeft++;
        }
        else{
            temp[templeft] = data[left];
            left++;
            templeft++;
        }
    }

    while(left<=origcenter-1){
        temp[templeft] = data[left];
        left++;
        templeft++;
    }
    while(center<=right){
        temp[templeft] = data[center];
        center++;
        templeft++;
    }

    for(int i=0; i<origright-origleft+1; i++{
        data[right] = temp[right];
        right--;
    }
}

int main()
{
    cout<<"unsorted:\n";
    for(int i=0; i<9; i++){
        cout<<data[i]<<" ";
    }

    mergesort(0,8);

    cout<<"\nsorted:\n";
    for(int i=0;i<9;i++){
        cout<<data[i]<<" ";
    }

    return 0;
}
