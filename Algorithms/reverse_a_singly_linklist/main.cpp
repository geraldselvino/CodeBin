/**********************************************
* Author: Gerald Selvino
* Description: Reverse a singly linked list demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

struct linklist{
    int a;
    struct linklist* next;
};

int main()
{
    linklist a = {1,NULL};
    linklist b = {2,NULL};
    linklist c = {3,NULL};

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    linklist* p = &a;
    linklist* current;
    linklist* tmp;

    while(p){
        cout<<p->a<<" ";
        p = p->next;
    }
    p = &a;
    current = p->next;
    p->next = NULL;

    while(current){
        tmp = current->next;
        current->next = p;
        p = current;
        current = tmp;
    }

    cout<<endl;

    while(p){
        cout<<p->a<<" ";
        p = p->next;
    }

    return 0;
}
