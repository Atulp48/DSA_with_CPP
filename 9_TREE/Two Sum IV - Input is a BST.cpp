#include <bits/stdc++.h> 
#include<vector>
// Following is the Binary Tree node structure
/**************
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
***************/

void shorted(BinaryTreeNode<int>* root, vector<int>&shorting){
    if(root==NULL){
        return ;

    }

   shorted(root->left,shorting);
   shorting.push_back(root->data); 
   shorted(root->right,shorting);

}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector <int> shortedval;
    shorted(root,shortedval);

    int i,j;
    i=0;
    j=shortedval.size()-1;
    while(i<j){
        int flag=shortedval[i]+shortedval[j];
        if(flag==target){
            return true;
        }
        else if(flag<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;

}