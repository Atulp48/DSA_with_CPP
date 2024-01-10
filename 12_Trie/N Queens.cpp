#include <bits/stdc++.h>

void add(vector<vector<int>> &result, vector<vector<int>> &plane, int n)
{
    vector<int> store;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            store.push_back(plane[i][j]);
        }
    }
    result.push_back(store);
}

bool isRight(int rw, int cl, vector<vector<int>> &plane, int n)
{
    int i, j;
    i = rw;
    j = cl;
    while (j >= 0)
    {
        if (plane[i][j] == 1)
        {
            return false;
        }
        j--;
    }

    i = rw;
    j = cl;

    while (i >= 0 && j >= 0)
    {
        if (plane[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    i = rw;
    j = cl;

    while (i < n && j >= 0)
    {
        if (plane[i][j] == 1)
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void answer(int cl, vector<vector<int>> &result, vector<vector<int>> &plane, int n)
{

    if (cl == n)
    {
        add(result, plane, n);
        return;
    }

    for (int rw = 0; rw < n; rw++)
    {
        if (isRight(rw, cl, plane, n))
        {
            plane[rw][cl] = 1;
            answer(cl + 1, result, plane, n);
            plane[rw][cl] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> plane(n, vector<int>(n, 0));
    vector<vector<int>> result;

    answer(0, result, plane, n);
    return result;
}