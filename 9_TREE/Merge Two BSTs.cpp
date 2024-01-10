#include<bits/stdc++.h>
using namespace std;
{
    
} // namespace std;

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void storeInOrder(TreeNode *root, vector<int> &in)
{
    if (root != NULL)
    {
        storeInOrder(root->left, in);
        in.push_back(root->data);
        storeInOrder(root->right, in);
    }
}


vector<int> mergeSortedArrays(vector<int> &bst1, vector<int> &bst2)
{
    int i = 0, j = 0;
    vector<int> ans;

    
    while (i < bst1.size() && j < bst2.size())
    {
     
        if (bst1[i] < bst2[j])
        {
            ans.push_back(bst1[i]);
            i++;
        }
        else
        {
            ans.push_back(bst2[j]);
            j++;
        }
    }


    while (i < bst1.size())
    {
        ans.push_back(bst1[i]);
        i++;
    }


    while (j < bst2.size())
    {
        ans.push_back(bst2[j]);
        j++;
    }

    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
   
    vector<int> temp1;
    storeInOrder(root1, temp1);

    
    vector<int> temp2;
    storeInOrder(root2, temp2);

   
    vector<int> answer = mergeSortedArrays(temp1, temp2);

    return answer;
}