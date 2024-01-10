#include <bits/stdc++.h>

class Solution
{

    vector<vector<int>> dp;

private:
    int solution(int i, int j, vector<int> &V)
    {

        int result = INT_MAX;

        if (i + 1 == j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        for (int k = i + 1; k < j; k++)
        {

            result = min(result, V[i] * V[j] * V[k] + solution(i, k, V) + solution(k, j, V));
        }
        dp[i][j] = result;
        return dp[i][j];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        dp.resize(n, vector<int>(n, -1));
        return solution(0, n - 1, values);
    }
};

