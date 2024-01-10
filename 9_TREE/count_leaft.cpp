/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    
***********************************************************/


void IO(BinaryTreeNode<int> *root,int &flag)
{
    if (root == NULL)
    {
        return;
    }
    IO(root->left,flag);
    if(root->right==NULL && root->left==NULL){
        flag=flag+1;
    }
    IO(root->right,flag);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
 int flag =0;
 IO(root,flag);
 return flag;
 

}