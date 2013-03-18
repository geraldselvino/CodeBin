/**********************************************
* Author: Gerald Selvino
* Description: Traverse a binary tree using
*              Breadth First Search demo
* Language: C++
***********************************************/
#include <iostream>
#include <list>

using namespace std;

struct binarytree{
    string data;
    struct binarytree* left;
    struct binarytree* right;
};

list<binarytree*> myqueue;
list<binarytree*>::iterator myqueueiterate;

void bfs(binarytree* node);

void breadthfirstsearch(binarytree* root){
    myqueue.push_back(root);
    myqueueiterate = myqueue.begin();
    bfs(*myqueueiterate);
}

void bfs(binarytree* node){
    if(myqueueiterate == myqueue.end())return;
    cout<<node->data<<endl;
    if(node->left)myqueue.push_back(node->left);
    if(node->right)myqueue.push_back(node->right);
    ++myqueueiterate;
    bfs(*myqueueiterate);
}

int main()
{
    //Build the tree
    binarytree leftsecondlevel = {"leftsecond",NULL,NULL};
    binarytree rightsecondlevel = {"rightsecond",NULL,NULL};
    binarytree leftsecondlevel2 = {"leftsecond2",NULL,NULL};
    binarytree rightsecondlevel2 = {"rightsecond2",NULL,NULL};

    binarytree leftfirstlevel = {"leftfirst",&leftsecondlevel,&rightsecondlevel};
    binarytree rightfirstlevel = {"rightfirst",&leftsecondlevel2,&rightsecondlevel2};

    binarytree rootnode = {"rootnode",&leftfirstlevel,&rightfirstlevel};

    cout <<endl;

    //Traverse using BFS
    breadthfirstsearch(&rootnode);

    return 0;
}
