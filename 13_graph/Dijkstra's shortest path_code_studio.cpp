#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source)
{
    unordered_map<int, list<pair<int, int>>> grph;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        grph[u].push_back(make_pair(v, w));
        grph[v].push_back(make_pair(u, w));
    }

    vector<int> distance(vertices);

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    distance[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {

        auto top = *(st.begin());

        int node_dist = top.first;
        int node_top = top.second;

        st.erase(st.begin());

        for (auto neighbour : grph[node_top])
        {
            if (node_dist + neighbour.second < distance[neighbour.first])
            {

                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                distance[neighbour.first] = node_dist + neighbour.second;
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }
    return distance;
}
