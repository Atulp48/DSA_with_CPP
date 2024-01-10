#include<bits/stdc++.h>

void dfs(int node, unordered_map<int, bool> &visit, unordered_map<int, list<int>> &grph, vector<int> &compo)
{
    compo.push_back(node);
    visit[node] = true;

    for (auto i : grph[node])
    {
        if (!visit[i])
        {
            dfs(i, visit, grph, compo);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> grph;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        grph[u].push_back(v);
        grph[v].push_back(u);
    }

    vector<vector<int>> result;
    unordered_map<int, bool> visit;

    for (int i = 0; i < V; i++)
    {
        if (!visit[i])
        {
            vector<int> compo;
            dfs(i, visit, grph, compo);
            result.push_back(compo);
        }
    }
    return result;
}