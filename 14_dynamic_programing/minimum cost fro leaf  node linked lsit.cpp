// the problem is solved with the help of recursion  for understanding but get time limit exceeded

class Solution
{

private:
    int solve(vector<int> &arr, map<pair<int, int>, int> &result, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }
        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, result[{left, i}] * result[{i + 1, right}] + solve(arr, result, left, i) + solve(arr, result, i + 1, right));
        }
        return ans;
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> result;

        for (int i = 0; i < arr.size(); i++)
        {
            result[{i, i}] = arr[i];

            for (int j = i + 1; j < arr.size(); j++)
            {
                result[{i, j}] = max(result[{i, j - 1}], arr[j]);
            }
        }
        return solve(arr, result, 0, arr.size() - 1);
    }
};

// the porblem  solved with the help of dinamic programming. and passed all test cases

class Solution
{
    vector<vector<int>> dp;

private:
    int solve(vector<int> &arr, map<pair<int, int>, int> &result, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, result[{left, i}] * result[{i + 1, right}] + solve(arr, result, left, i) + solve(arr, result, i + 1, right));
        }
        return dp[left][right] = ans;
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> result;
        dp.resize(arr.size() + 1, vector<int>(arr.size() + 1, -1));

        for (int i = 0; i < arr.size(); i++)
        {
            result[{i, i}] = arr[i];

            for (int j = i + 1; j < arr.size(); j++)
            {
                result[{i, j}] = max(result[{i, j - 1}], arr[j]);
            }
        }
        return solve(arr, result, 0, arr.size() - 1);
    }
};