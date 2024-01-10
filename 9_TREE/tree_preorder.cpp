#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int data;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node *BT(node *root)
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter left " << data << endl;
    root->left = BT(root->left);
    cout << "enter right " << data << endl;
    root->right = BT(root->right);
    return root;
}

void LOT(node *root)
{
    queue<node *> ans;
    ans.push(root);
    ans.push(NULL);

    while (!ans.empty())
    {
        node *flag = ans.front();

        ans.pop();

        if (flag == NULL)
        {
            cout << endl;
            if (!ans.empty())
            {
                ans.push(NULL);
            }
        }

        else
        {
            cout << flag->data << " ";
            if (flag->left)
            {
                ans.push(flag->left);
            }

            if (flag->right)
            {
                ans.push(flag->right);
            }
        }
    }
}

void PO(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PO(root->left);
    
    PO(root->right);
}

int main()
{

    node *root = NULL;
    root = BT(root);
    LOT(root);
    cout<<"preorder traversal"<<endl;
    PO(root);
    return 0;
}
