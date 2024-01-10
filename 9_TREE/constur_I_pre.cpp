//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

THIS SOLUTION IS NOT PASSED ALL TEST CASE  

class Solution{
    public:
    
    int findposition(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element)
             return i;
        }
        return -1;
    }
    
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
        
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        
        int element=pre[index++];
        Node* root=new Node(element);
        int position=findposition(in,element,n);
        
        root->left=solve(in,pre,index,inorderStart,position-1,n);
        root->right=solve(in,pre,index,position+1,inorderEnd,n);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex=0;
      Node* ans=  solve(in,pre,preOrderIndex,0,n-1,n);
      return ans;
    }
};

THIS SOLUTION IS PASSED ALL CURRENT TEST CASE


class Solution{
  public:
    int findIndex(int arr[], int start, int target)
    {
        int i=0;
        while( arr[start+i] != target ) i++;
        return i;
    }
    
    Node* buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
    {
        if(n==0) return NULL;
        
        Node* ret = new Node( preorder[preStart] );
        
        int i = findIndex( inorder, inStart, preorder[preStart] );
        
        ret->left = buildUtil( inorder, preorder, inStart, preStart+1, i );
        ret->right = buildUtil( inorder, preorder, inStart+i+1, preStart+i+1, n-i-1 );
        
        return ret;
    }
    
    Node *buildTree(int inorder[], int preorder[], int n)
    {
        return buildUtil(inorder, preorder, 0, 0, n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends