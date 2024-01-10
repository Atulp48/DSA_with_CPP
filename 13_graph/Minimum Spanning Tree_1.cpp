#include <bits/stdc++.h>

static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void intilize_value(vector<int> &rank, vector<int> &parent, int n)
{

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(int node, vector<int> &parent)
{

    if (parent[node] == node)
    {
        return node;
    }

    parent[node] = find_parent(parent[node], parent);

    return parent[node];
}

void union_operation(vector<int> &parent, int first_node, int second_node, vector<int> &rank)
{

    first_node = find_parent(first_node, parent);
    second_node = find_parent(second_node, parent);

    if (rank[first_node] > rank[second_node])
    {
        parent[second_node] = first_node;
        rank[first_node]++;
    }

    else if (rank[first_node] < rank[second_node])
    {
        parent[first_node] = second_node;
        rank[second_node]++;
    }

    else
    {
        parent[second_node] = first_node;
        rank[first_node]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    int min_weight = 0;

    intilize_value(rank, parent, n);

    for (int i = 0; i < edges.size(); i++)
    {
        int first_node = find_parent(edges[i][0], parent);
        int second_node = find_parent(edges[i][1], parent);
        int weight_node = edges[i][2];

        if (first_node != second_node)
        {
            min_weight = min_weight + weight_node;
            union_operation(parent, first_node, second_node, rank);
        }
    }

    return min_weight;
}
