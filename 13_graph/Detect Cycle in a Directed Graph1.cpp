#include <bits/stdc++.h>
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> grph;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        grph[u].push_back(v);
    }

    vector<int> indegree(v);
    for (auto i : grph)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbour : grph[front])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    if (count == v)
    {
        return false;
    }
    else
    {
        return true;
    }
}
