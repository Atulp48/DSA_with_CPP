#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template<typename T>

class graph
{

public:
    unordered_map<T, list<T>> adj;

    void addEdg(T u, T v, bool direction)
    {

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printgraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    int edge, nodes;

    cout << "enter the number of the nodes" << endl;
    cin >> nodes;

    cout << "enter the number of edges" << endl;
    cin >> edge;

    graph<int> g;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdg(u, v, 0);
    }
    cout<<"the representation of the graph is "<<endl;
    g.printgraph();

    return 0;
}