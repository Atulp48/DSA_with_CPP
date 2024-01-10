#include<bits/stdc++.h>

class Graph
{

public:
    bool detectCycle(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        int parent_node = 1;
        queue<int> q;
        q.push(parent_node);
        bool flag = false;

        while (!q.empty())
        {
            int front_node = q.front();
            if (visited[front_node] == true)
            {
                flag = true;
            }
            visited[front_node] = true;
            q.pop();

            for (auto neighbour : adj[front_node])
            {
                if (visited[neighbour] == false)
                {
                    q.push(neighbour);
                }
            }
        }
        return flag;
    }
};