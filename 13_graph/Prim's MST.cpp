#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> grph;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        grph[u].push_back(make_pair(v, w));
        grph[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<int> parent(n + 1);
    vector<bool> MST(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        MST[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mn = INT_MAX;
        int find_node;

        for (int j = 1; j <= n; j++)
        {

            if (MST[j] == false && key[j] < mn)
            {
                find_node = j;
                mn = key[j];
            }
        }

        MST[find_node] = true;

        for (auto adj_node : grph[find_node])
        {
            int v = adj_node.first;
            int w = adj_node.second;
            if (MST[v] == false && w < key[v])
            {
                parent[v] = find_node;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return result;
}
