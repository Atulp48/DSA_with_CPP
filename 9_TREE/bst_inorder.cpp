#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *ins(Node *root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = ins(root->right, data);
    }
    else
    {
        root->left = ins(root->left, data);
    }

    return root;
}

void IN(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    IN(root->left);
    cout << root->data << " ";

    IN(root->right);
}

void input(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = ins(root, data);
        cin >> data;
    }
}

int main()
{
    Node *root = NULL;
    cout << "enter the value" << endl;
    input(root);
    cout << "the representation of the tree in inorder " << endl;
    IN(root);

    return 0;
}