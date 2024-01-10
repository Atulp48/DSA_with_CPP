#include <bits/stdc++.h>
int answer(int n, int x, int y, int z)
{
    if (n < 0)
    {
        return INT_MIN;
    }

    if (n == 0)
    {
        return 0;
    }

    int cut1, cut2, cut3, result;

    cut1 = answer(n - x, x, y, z) + 1;
    cut2 = answer(n - y, x, y, z) + 1;
    cut3 = answer(n - z, x, y, z) + 1;

    result = max(cut1, max(cut2, cut3));
    return result;
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> store1;

    int store = answer(n, x, y, z);

    if (store < 0)
    {
        return 0;
    }
    return store;
}

// the following solution contains dynamic programing  for accepetance of the codestudio solution

#include <bits/stdc++.h>
int answer(vector<int> &store1, int n, int x, int y, int z)
{
    if (n < 0)
    {
        return INT_MIN;
    }

    if (n == 0)
    {
        return 0;
    }
    if (store1[n] != -1)
    {
        return store1[n];
    }

    int cut1, cut2, cut3;

    cut1 = answer(store1, n - x, x, y, z) + 1;
    cut2 = answer(store1, n - y, x, y, z) + 1;
    cut3 = answer(store1, n - z, x, y, z) + 1;

    store1[n] = max(cut1, max(cut2, cut3));
    return store1[n];
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> store1(n + 1, -1);

    int result = answer(store1, n, x, y, z);
    if (result < 0)
    {
        return 0;
    }
    return result;
}

// the following method is used to tabulation method for solving the above problem

#include <bits/stdc++.h>
int answer(int n, int x, int y, int z)
{
    vector<int> store1(n + 1, INT_MIN);
    store1[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
        {
            store1[i] = max(store1[i], store1[i - x] + 1);
        }

        if (i - y >= 0)
        {
            store1[i] = max(store1[i], store1[i - y] + 1);
        }

        if (i - z >= 0)
        {
            store1[i] = max(store1[i], store1[i - z] + 1);
        }
    }

    if (store1[n] < 0)
    {
        return 0;
    }
    return store1[n];
}

int cutSegments(int n, int x, int y, int z)
{

    return answer(n, x, y, z);
}



