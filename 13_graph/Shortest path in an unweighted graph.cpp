#include <bits/stdc++.h>

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, list<int>> GRPH;
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;
    queue<int> q;
    visited[s] = true;
    parent[s] = -1;
    q.push(s);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        GRPH[u].push_back(v);
        GRPH[v].push_back(u);
    }

    while (!q.empty())
    {
        int front_node = q.front();
        q.pop();

        for (auto neighbour : GRPH[front_node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front_node;
                q.push(neighbour);
            }
        }
    }

    vector<int> result;

    int current_node = t;
    result.push_back(current_node);

    while (current_node != s)
    {
        current_node = parent[current_node];
        result.push_back(current_node);
    }
    reverse(result.begin(), result.end());
    return result;
}
