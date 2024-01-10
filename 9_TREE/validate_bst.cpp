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

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
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

bool checkBST(BinaryTreeNode<int>* root,int mx,int mn){
    if(root==NULL){
        return true;
    }
    if(root->data>mn && root->data<mx){
        bool left =checkBST(root->left,root->data,mn);
        bool right =checkBST(root->right,mx,root->data);
        return left && right;
    }
    else{
        return false;
    }
}


bool validateBST(BinaryTreeNode<int>* root) 
{
    return checkBST(root,INT_MAX,INT_MIN);
}