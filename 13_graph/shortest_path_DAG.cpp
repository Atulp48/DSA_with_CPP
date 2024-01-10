#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> grph;

    void addEdges(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        grph[u].push_back(p);
    }

    void print_edges()
    {
        for (auto i : grph)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;

        for (auto neighbour : grph[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

    void getshortestPath(int source, vector<int> &path, stack<int> &s)
    {
        path[source] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (path[top] != INT_MAX)
            {
                for (auto neighbour : grph[top])
                {
                    if ((path[top] + neighbour.second) < path[neighbour.first])
                    {
                        path[neighbour.first] = path[top] + neighbour.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;

    g.addEdges(0, 1, 5);
    g.addEdges(0, 2, 3);
    g.addEdges(1, 2, 2);
    g.addEdges(1, 3, 6);
    g.addEdges(2, 3, 7);
    g.addEdges(2, 4, 4);
    g.addEdges(2, 5, 2);
    g.addEdges(3, 4, -1);
    g.addEdges(4, 5, -2);

    g.print_edges();

    unordered_map<int, bool> visited;
    stack<int> s;
    int n = 6;

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int source = 1;
    vector<int> path(n);

    for (int i = 0; i < n; i++)
    {
        path[i] = INT_MAX;
    }

    g.getshortestPath(source, path, s);

    cout << "the path is" << endl;

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << "  ";
    }
    cout << endl;
    return 0;
}