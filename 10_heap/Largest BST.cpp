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
#include <bits/stdc++.h>
class answer
{
public:
    int mx;
    int mn;
    bool flag;
    int s;
};

answer solution(TreeNode<int> *root, int &ans)
{

    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    answer left = solution(root->left, ans);
    answer right = solution(root->right, ans);

    answer curNode;

    curNode.s = left.s + right.s + 1;
    curNode.mx = max(root->data, right.mx);
    curNode.mn = min(root->data, left.mn);

    if (left.flag && right.flag && (root->data > left.mx && root->data < right.mn))
    {
        curNode.flag = true;
    }
    else
    {
        curNode.flag = false;
    }

    if (curNode.flag)
    {
        ans = max(ans, curNode.s);
    }
    return curNode;
}

int largestBST(TreeNode<int> *root)
{
    int ans = 0;
    answer flag = solution(root, ans);
    return ans;
}