#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> *flag=root;
    while(flag!=NULL){
        if(flag->data==x){
        return true;
    }
    if(flag->data==x){
        return true;
    }
    if(flag->data<x){
       flag=flag->right;
    }
    else{
     flag=flag->left;
    }
    }
    return false;
}