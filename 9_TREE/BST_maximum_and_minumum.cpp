#include<iostream>
#include<queue>
using namespace std;

class Node{
public:

int data;
Node*left;
Node* right;

Node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;

}



};

Node* ins(Node *root,int data){

if(root== NULL)
{
    root=new Node(data);
    return root;
}

if(data>root->data){
    root->right=ins(root->right,data);
}
else{
     root->left=ins(root->left,data);
}

return root;

}

Node* maxv(Node*root){
    Node* flag=root;
    while(flag->right!=NULL){
        flag=flag->right;
    }
    return flag;
}

Node* minv(Node*root){
    Node* flag=root;
    while(flag->left!=NULL){
        flag=flag->left;
    }
    return flag;
}

Node* del(Node* root,int val){
    if(root==NULL){
        return root;
    }

    if(root->data==val){
        if(root->left==NULL  && root->right==NULL){
            delete root;
            return NULL;
        }

         if(root->left!=NULL  && root->right==NULL){
            Node* flag=root->left;
            delete root;
            return flag;
        }
        if(root->left==NULL  && root->right!=NULL){
            Node* flag=root->right;
            delete root;
            return flag;
        }

          if(root->left!=NULL  && root->right!=NULL){
            int flag=minv(root->right)->data;
            root->data=flag;
            root->right=del(root->right,flag);
            return root;  
        }
    }
    else if(root->data<val){
      root->right=del(root->right,val);
      return root;
    }
    else{
        root->left=del(root->left,val);
        return root;
    }
}

void LOT(Node *root)
{
    queue<Node *> ans;
    ans.push(root);
    ans.push(NULL);

    while (!ans.empty())
    {
        Node *flag = ans.front();

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

void input(Node* &root ){
    int data;
    cin>>data;

    while(data!=-1){
      root=  ins(root,data);
        cin>>data;

    }
}

int main(){
    
    Node*root=NULL;
    cout<<"enter the value"<<endl;
    input(root);
    cout<<"the representation of the tree is "<<endl;
    LOT(root);

    root=del(root,50);

    cout<<"the representation of the tree after deletion  "<<endl;
    LOT(root);
    
     return 0;
}