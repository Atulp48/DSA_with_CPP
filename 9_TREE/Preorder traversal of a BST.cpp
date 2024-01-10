#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int>* answer(vector<int> &preorder,int &flag,int large,int small){
    if((flag>=preorder.size())|| (preorder[flag]<small || preorder[flag]>large)){
        return NULL;
    }

   BinaryTreeNode<int>* val=new BinaryTreeNode<int>(preorder[flag++]);
   val->left=answer(preorder,flag,val->data,small);
   val->right=answer(preorder,flag,large,val->data);
   return val;

}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
int flag=0;
int large=INT_MAX;
int small=INT_MIN;
return answer(preorder,flag,large,small);   
}