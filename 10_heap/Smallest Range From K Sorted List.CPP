#include <bits/stdc++.h>
class Node
{
public:
    int data;
    int row;
    int col;

    Node(int val, int i, int j)
    {
        this->data = val;
        this->row = i;
        this->col = j;
    }
};

class check
{
public:
    bool operator()(Node *x, Node *y) { return x->data > y->data; }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{

    int mn = INT_MAX;
    int mx = INT_MIN;

    priority_queue<Node *, vector<Node *>, check> flag;

    for (int i = 0; i < k; i++)
    {
        int temp = a[i][0];
        mn = min(mn, temp);
        mx = max(mx, temp);
        flag.push(new Node(temp, i, 0));
    }

    int s = mn;
    int e = mx;

    while (!flag.empty())
    {

        Node *temp = flag.top();
        flag.pop();

        mn = temp->data;

        if (mx - mn < e - s)
        {
            s = mn;
            e = mx;
        }

        if (temp->col + 1 < n)
        {
            mx = max(mx, a[temp->row][temp->col + 1]);
            flag.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }

        else
        {
            break;
        }
    }

    return (e - s + 1);
}