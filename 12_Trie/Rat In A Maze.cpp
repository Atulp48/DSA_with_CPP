#include <bits/stdc++.h>

bool director(int a, int b, vector<vector<bool>> &check, vector<vector<int>> &arr, int n)
{

    if ((b >= 0 && b < n) && (a >= 0 && a < n) && (check[a][b] != 1 && arr[a][b] == 1))
    {

        return true;
    }

    else
    {
        return false;
    }
}

void answer(int a, int b, vector<vector<int>> &arr, int n, vector<string> &result, vector<vector<bool>> &check, string route)
{
    if (a == n - 1 && b == n - 1)
    {
        result.push_back(route);
        return;
    }

    check[a][b] = 1;

    //   D
    if (director(a + 1, b, check, arr, n))
    {

        answer(a + 1, b, arr, n, result, check, route + 'D');
    }

    // L
    if (director(a, b - 1, check, arr, n))
    {

        answer(a, b - 1, arr, n, result, check, route + 'L');
    }

    // R
    if (director(a, b + 1, check, arr, n))
    {

        answer(a, b + 1, arr, n, result, check, route + 'R');
    }

    // U
    if (director(a - 1, b, check, arr, n))
    {

        answer(a - 1, b, arr, n, result, check, route + 'U');
    }
    check[a][b] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    // Write your code here.
    vector<string> result;
    vector<vector<bool>> check(n, vector<bool>(n, 0));
    string route = "";

    if (arr[0][0] == 0)
    {
        return result;
    }

    answer(0, 0, arr, n, result, check, route);
    return result;
}