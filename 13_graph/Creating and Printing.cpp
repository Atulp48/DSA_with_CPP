#include <bits/stdc++.h>

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
  vector<vector<int>> store(n);
  // vector<int>store[n];

  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    store[u].push_back(v);
    store[v].push_back(u);
  }

  vector<vector<int>> grph(n);

  for (int i = 0; i < n; i++)
  {
    grph[i].push_back(i);
    for (int j = 0; j < store[i].size(); j++)
    {
      grph[i].push_back(store[i][j]);
    }
  }
  return grph;
}