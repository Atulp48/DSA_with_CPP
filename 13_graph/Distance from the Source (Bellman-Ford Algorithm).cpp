//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> distance(V, 1e8);
        int size = edges.size();

        distance[S] = 0;

        vector<int> ans(V);

        for (int i = 1; i < V; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                if (distance[u] != 1e8 && (distance[u] + weight < distance[v]))
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        bool flag = true;

        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                if (distance[u] != 1e8 && (distance[u] + weight < distance[v]))
                {
                    flag = false;
                }
            }
        }
        vector<int> temp;
        temp.push_back(-1);

        if (flag == true)
        {
            return distance;
        }

        else
        {
            return temp;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends