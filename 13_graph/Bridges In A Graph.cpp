#include <bits/stdc++.h>

void dfs(int node, int parent, int &timer, vector<int> &discovery_time, vector<int> &low_time, vector<vector<int>> &result,
         unordered_map<int, list<int>> &grph, unordered_map<int, bool> &visited)
{

    visited[node] = true;
    discovery_time[node] = timer;
    low_time[node] = timer;
    timer++;

    for (auto neighbour : grph[node])
    {

        if (neighbour == parent)
        {
            continue;
        }

        if (!visited[neighbour])
        {
            dfs(neighbour, node, timer, discovery_time, low_time, result, grph,
                visited);
            low_time[node] = min(low_time[neighbour], low_time[node]);

            if (discovery_time[node] < low_time[neighbour])
            {
                result.push_back({node, neighbour});
            }
        }
        else
        {
            low_time[node] = min(low_time[node], discovery_time[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    vector<vector<int>> result;
    unordered_map<int, list<int>> grph;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        grph[u].push_back(v);
        grph[v].push_back(u);
    }

    int timer = 0;
    int parent = -1;

    unordered_map<int, bool> visited;
    vector<int> discovery_time(v);
    vector<int> low_time(v);

    parent = -1;

    for (int i = 0; i < v; i++)
    {
        discovery_time[i] = -1;
        low_time[i] = -1;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, discovery_time, low_time, result, grph, visited);
        }
    }

    return result;
}