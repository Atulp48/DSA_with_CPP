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


void BlO(node* &root)
{
    queue<node *> ans;
    int val;

    cout << "enter root data" << endl;
    cin >> val;
    root = new node(val);
    ans.push(root);

    while (!ans.empty())
    {
        node *flag = ans.front();
        ans.pop();
  
        cout<<"enter left node "<<flag->data<<endl;
        int ld;
        cin>>ld;

        if(ld!=-1){
            flag->left=new node(ld);
            ans.push(flag->left);
        }

        
        cout<<"enter right node "<<flag->data<<endl;
        int rd;
        cin>>rd;

        if(rd!=-1){
            flag->right=new node(rd);
            ans.push(flag->right);
        }

    }
}


int main()
{

    node *root = NULL;
    BlO(root); 
    LOT(root);
    return 0;
}
