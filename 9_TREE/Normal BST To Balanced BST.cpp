#include<vector>
#include <bits/stdc++.h>
/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void shorted(TreeNode<int> *root, vector<int> &shorting)
{
    if (root == NULL)
    {
        return;
    }

    shorted(root->left, shorting);
    shorting.push_back(root->data);
    shorted(root->right, shorting);
}

TreeNode<int> *shortedBst(int s, int e, vector<int> &shortedval)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (e + s) / 2;
    TreeNode<int> *flag = new TreeNode<int>(shortedval[mid]);
    flag->left = shortedBst(s, mid - 1, shortedval);
    flag->right = shortedBst(mid + 1, e, shortedval);
    return flag;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{

    vector<int> shortedval;
    shorted(root, shortedval);
    int size = shortedval.size() - 1;

    return shortedBst(0, size, shortedval);
}
