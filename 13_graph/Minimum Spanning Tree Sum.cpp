#include <bits/stdc++.h>

vector<vector<int>> findMST(vector<vector<int>> &g, int n, int m)
{
    unordered_map<int, list<pair<int, int>>> grph;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i][0];
        int v = g[i][1];
        int w = g[i][2];

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

    vector<vector<int>> RESULT;

    for (int i = 2; i <= n; i++)
    {
        vector<int> STORE;
        STORE.push_back(parent[i]);
        STORE.push_back(i);
        STORE.push_back(key[i]);
        RESULT.push_back(STORE);
    }

    return RESULT;
}

//  the following code is same as above code  in the following code is   only change in last part when we stare
// the the parent and key and node value is vector  datastructure


#include <bits/stdc++.h>

vector<vector<int>> findMST(vector<vector<int>> &g, int n, int m)
{
    unordered_map<int, list<pair<int, int>>> grph;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i][0];
        int v = g[i][1];
        int w = g[i][2];

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

    vector<vector<int>> RESULT;

    for (int i = 2; i <= n; i++)
    {
        RESULT.push_back({parent[i], i, key[i]});
    }

    return RESULT;
}