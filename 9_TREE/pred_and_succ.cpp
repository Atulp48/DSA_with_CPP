#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>*temp= root;
    int pr,sc;
    pr=-1;
    sc=-1;

    while(temp->data!=key){

        if(temp->data>key){
       sc=temp->data; 
       temp=temp->left;
        
    }   
    else {
         pr=temp->data;
        temp=temp->right;
      }

        }

BinaryTreeNode<int>* leftval=temp->left;
while(leftval!=NULL){
    pr=leftval->data;
    leftval=leftval->right;
}

BinaryTreeNode<int>* rightval=temp->right;
while(rightval!=NULL){
    sc=rightval->data;
    rightval=rightval->left;
}

pair<int,int>flag=make_pair(pr,sc);
return flag;

      
 }

