/**********************************************
* Author: Gerald Selvino
* Description: Binary Search demo, recursive version
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

bool binarySearch(int data[], int search_keyword, int start, int end){
    int middle_index = (start+end)/2;

    if(start<=end){
        if(data[middle_index]==search_keyword) return true;
        else if(data[middle_index]<search_keyword){
            return binarySearch(data, search_keyword, middle_index+1, end);
        }
        else{
            return binarySearch(data, search_keyword, start, middle_index-1);
        }
    }
    return false;
}

int main()
{
    int data[]={1,2,3,4,5,6,7,8,9};

    if(binarySearch(data, 11, 0, 8)){
        cout<<"item found";
    }
    else{
        cout<<"item not found";
    }
    return 0;
}
