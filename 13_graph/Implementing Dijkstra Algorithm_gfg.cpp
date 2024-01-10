//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> dijkstra(int vertices, vector<vector<int>> adj[], int source)
    {
        vector<int> distance(vertices);

        for (int i = 0; i < vertices; i++)
        {
            distance[i] = INT_MAX;
        }

        set<pair<int, int>> st;

        distance[source] = 0;
        st.insert(make_pair(0, source));

        while (!st.empty())
        {

            auto top = *(st.begin());

            int node_dist = top.first;
            int node_top = top.second;

            st.erase(st.begin());

            for (auto neighbour : adj[node_top])
            {
                if (node_dist + neighbour[1] < distance[neighbour[0]])
                {

                    auto record = st.find(make_pair(distance[neighbour[0]], neighbour[0]));

                    if (record != st.end())
                    {
                        st.erase(record);
                    }

                    distance[neighbour[0]] = node_dist + neighbour[1];
                    st.insert(make_pair(distance[neighbour[0]], neighbour[0]));
                }
            }
        }
        return distance;
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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends