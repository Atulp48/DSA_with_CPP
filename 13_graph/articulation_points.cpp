#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, vector<int> &discovery_node, vector<int> &low_distance,
         unordered_map<int, bool> &visited_node, unordered_map<int, list<int>> &grph,
         vector<int> &articulation_point, int &timer)
{
    int count = 0;
    visited_node[node] = true;
    discovery_node[node] = timer;
    low_distance[node] = timer;
    timer++;

    for (auto neighbour : grph[node])
    {
        if (neighbour == parent)
        {
            continue;
        }
        if (!visited_node[neighbour])
        {
            dfs(neighbour, node, discovery_node, low_distance, visited_node, grph, articulation_point, timer);
            low_distance[node] = min(low_distance[node], low_distance[neighbour]);

            if (low_distance[neighbour] >= discovery_node[node] && parent != -1)
            {
                articulation_point[node] = 1;
            }
            count++;
        }
        else
        {
            low_distance[node] = min(low_distance[node], discovery_node[neighbour]);
        }
    }
    if (parent == -1 && count > 1)
    {
        articulation_point[node] = 1;
    }
}

int main()
{

    vector<pair<int, int>> edges;
    unordered_map<int, list<int>> grph;
    int size = 5;
    int e = 5;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        grph[u].push_back(v);
        grph[v].push_back(u);
    }

    vector<int> discovery_node(size);
    vector<int> low_distance(size);
    unordered_map<int, bool> visited_node;
    int timer = 0;
    vector<int> articulation_point(size, 0);

    for (int i = 0; i < size; i++)
    {
        discovery_node[i] = -1;
        low_distance[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (!visited_node[i])
        {
            dfs(i, -1, discovery_node, low_distance, visited_node, grph, articulation_point, timer);
        }
    }

    cout << "the articulation point present in graph is" << endl;

    for (int i = 0; i < size; i++)
    {

        if (articulation_point[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}