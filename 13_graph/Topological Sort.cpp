// the   problem is solved with the help of the DFS method

#include <bits/stdc++.h>

void topoligical_sort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &grph)
{

    visited[node] = true;

    for (auto neighbour : grph[node])
    {
        if (!visited[neighbour])
        {
            topoligical_sort(neighbour, visited, s, grph);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, list<int>> grph;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        grph[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoligical_sort(i, visited, s, grph);
        }
    }

    vector<int> result;

    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

// the above problem is solved with the help of the  BFS  method in following code

#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, list<int>> grph;

    for (int i = 0; i < e; i++)
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

    vector<int> result;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        result.push_back(front);

        for (auto neighbour : grph[front])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return result;
}