#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/

int answer(BinaryTreeNode<int>* root,int &i, int k){
    if(root==NULL){
        return -1;
    }
    int left=answer(root->left,i,k);

    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return answer(root->right,i,k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
  int temp=0;
    int flag =answer(root,temp,k);
    return flag;

}