//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void dfs(int node, vector<vector<int>> &adj, stack<int> &s, unordered_map<int, bool> &visited)
    {
        visited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adj, s, visited);
            }
        }
        s.push(node);
    }

    void dfs_for_transpose(int top, vector<vector<int>> &transpose_grph,
                           unordered_map<int, bool> &visited)
    {

        visited[top] = true;

        for (auto neighbour : transpose_grph[top])
        {
            if (!visited[neighbour])
            {
                dfs_for_transpose(neighbour, transpose_grph, visited);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {

        unordered_map<int, bool> visited;
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {

                dfs(i, adj, s, visited);
            }
        }

        vector<vector<int>> transpose_grph(V);

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            for (auto neighbour : adj[i])
            {

                transpose_grph[neighbour].push_back(i);
            }
        }

        int count = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (!visited[top])
            {
                count++;
                dfs_for_transpose(top, transpose_grph, visited);
            }
        }

        return count;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends