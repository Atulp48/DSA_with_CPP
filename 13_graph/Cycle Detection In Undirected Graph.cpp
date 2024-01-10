// the following code is solved the dyclic detection in  graph withe the help of the BFS method

#include <bits/stdc++.h>

bool isCylicBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &grph)
{

    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : grph[frontNode])
        {
            if (visited[neighbour] == true && neighbour != parent[frontNode])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    unordered_map<int, list<int>> grph;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        grph[u].push_back(v);
        grph[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCylicBFS(i, visited, grph))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// the problem of the cylic detection in graph is solved by the help  of the DFS method

#include <bits/stdc++.h>

bool isCylicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &grph)
{

    visited[node] = true;

    for (auto neighbour : grph[node])
    {
        if (!visited[neighbour])
        {
            if (isCylicDFS(neighbour, node, visited, grph))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    unordered_map<int, list<int>> grph;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        grph[u].push_back(v);
        grph[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCylicDFS(i, -1, visited, grph))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
