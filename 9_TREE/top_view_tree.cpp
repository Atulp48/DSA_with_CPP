//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> temp;
        if (root == NULL)
        {
            return temp;
        }

        map<int, int> val;
        queue<pair<Node *, int>> flag;

        flag.push(make_pair(root, 0));

        while (!flag.empty())
        {

            pair<Node *, int> ans = flag.front();
            flag.pop();
            Node *frontval = ans.first;
            int horizontal = ans.second;

            if (val.find(horizontal) == val.end())
            {
                val[horizontal] = frontval->data;
            }

            if (frontval->left)
            {
                flag.push(make_pair(frontval->left, horizontal - 1));
            }

            if (frontval->right)
            {
                flag.push(make_pair(frontval->right, horizontal + 1));
            }
        }

        for (auto i : val)
        {
            temp.push_back(i.second);
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends