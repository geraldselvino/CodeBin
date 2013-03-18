/**********************************************
* Author: Gerald Selvino
* Description: Traverse a binary tree using
*              PostOrder Depth First Search demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

struct binarytree{
    string data;
    struct binarytree* left;
    struct binarytree* right;
};

void postorder(binarytree* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
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

    //Traverse using postorder DFS
    postorder(&rootnode);

    return 0;
}
