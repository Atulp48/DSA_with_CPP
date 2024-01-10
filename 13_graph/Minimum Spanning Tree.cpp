//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int> key(n);
        vector<int> parent(n);
        vector<bool> MST(n);

        for (int i = 0; i < n; i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
            MST[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int i = 1; i < n; i++)
        {
            int mn = INT_MAX;
            int find_node = INT_MIN;

            for (int j = 0; j < n; j++)
            {

                if (MST[j] == false && key[j] < mn)
                {
                    find_node = j;
                    mn = key[j];
                }
            }

            MST[find_node] = true;

            for (auto adj_node : adj[find_node])
            {
                int v = adj_node[0];
                int w = adj_node[1];
                if (MST[v] == false && w < key[v])
                {
                    parent[v] = find_node;
                    key[v] = w;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = result + key[i];
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends