/**********************************************
* Author: Gerald Selvino
* Description: Traverse a binary tree using
*              InOrder Depth First Search demo
* Language: C++
***********************************************/
#include <iostream>

using namespace std;

struct binarytree{
    string data;
    struct binarytree* left;
    struct binarytree* right;
};

void inorder(binarytree* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
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

    //Traverse using inorder DFS
    inorder(&rootnode);

    return 0;
}
