#include <bits/stdc++.h>

bool cycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &grph)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : grph[node])
    {
        if (!visited[neighbour])
        {
            if (cycle(neighbour, visited, dfsvisited, grph))
            {
                return true;
            }
        }
        else if (dfsvisited[neighbour])
        {
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.

    unordered_map<int, list<int>> grph;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        grph[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (cycle(i, visited, dfsvisited, grph))
            {
                return true;
            }
        }
    }
    return false;
}