#include <bits/stdc++.h>

void dfs(int node, unordered_map<int, list<int>> &grph, stack<int> &s,
         unordered_map<int, bool> &visited)
{
    visited[node] = true;

    for (auto neighbour : grph[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, grph, s, visited);
        }
    }
    s.push(node);
}

void dfs_for_transpose(int top, unordered_map<int, list<int>> &transpose_grph,
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

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> grph;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        grph[u].push_back(v);
    }

    stack<int> s;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {

        if (!visited[i])
        {
            dfs(i, grph, s, visited);
        }
    }

    unordered_map<int, list<int>> transpose_grph;

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto neighbour : grph[i])
        {

            transpose_grph[neighbour].push_back(i);
        }
    }

    int store = 0;

    while (!s.empty())
    {
        auto top = s.top();
        s.pop();
        if (!visited[top])
        {
            store++;
            dfs_for_transpose(top, transpose_grph, visited);
        }
    }
    return store;
}