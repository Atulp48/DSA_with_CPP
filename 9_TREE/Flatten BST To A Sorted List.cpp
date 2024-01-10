#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void shorted(TreeNode<int>* root, vector<int>&shorting){
    if(root==NULL){
        return ;

    }

   shorted(root->left,shorting);
   shorting.push_back(root->data); 
   shorted(root->right,shorting);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{

     vector <int> shortedval;     
    shorted(root,shortedval);
    int size=shortedval.size();

    TreeNode<int>* temp= new TreeNode<int>(shortedval[0]);
    TreeNode<int>* flag=temp;


    for(int i=1;i<size;i++){
         TreeNode<int> *flag1=new TreeNode<int>(shortedval[i]);
         flag->left=NULL;
         flag->right=flag1;
         flag=flag1;

    }

    flag->left=NULL;
    flag->right=NULL;

return temp;    
    
}
