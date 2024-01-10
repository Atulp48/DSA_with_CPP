//  the problem is solved with the help of the dynamic programing and used memoisation method

class Solution
{

    vector<vector<int>> dp;
    int helper(vector<int> &prices, int n, int k, int ope, int index)
    {
        if (index == n || ope == 2 * k)
            return 0;

        if (dp[index][ope] != -1)
            return dp[index][ope];

        int profit = 0;
        if (ope % 2 == 0)
            profit = max(-prices[index] + helper(prices, n, k, ope + 1, index + 1), helper(prices, n, k, ope, index + 1));
        else
            profit = max(prices[index] + helper(prices, n, k, ope + 1, index + 1), helper(prices, n, k, ope, index + 1));
        return dp[index][ope] = profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        dp.resize(n, vector<int>(2 * k, -1));
        return helper(prices, n, k, 0, 0);
    }
};

// the problem is solved with the help of the dynamic programing and used tabulation method

class Solution
{

    vector<vector<int>> dp;

    int answer(vector<int> &prices, int k)
    {
        int n = prices.size();
        dp.resize(n + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int ope = 0; ope < 2 * k; ope++)
            {

                int profit = 0;
                if (ope % 2 == 0)
                {
                    profit = max(-prices[index] + dp[index + 1][ope + 1], dp[index + 1][ope]);
                }
                else
                {
                    profit = max(prices[index] + dp[index + 1][ope + 1], dp[index + 1][ope]);
                }

                dp[index][ope] = profit;
            }
        }

        return dp[0][0];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        return answer(prices, k);
    }
};

// the problem is solved with the help of the dynamic programing  and used the  space optimazation method

class Solution
{

    int answer(vector<int> &prices, int k)
    {
        int n = prices.size();

        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int ope = 0; ope < 2 * k; ope++)
            {

                int profit = 0;
                if (ope % 2 == 0)
                {
                    profit = max(-prices[index] + next[ope + 1], next[ope]);
                }
                else
                {
                    profit = max(prices[index] + next[ope + 1], next[ope]);
                }

                curr[ope] = profit;
            }
            next = curr;
        }

        return curr[0];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        return answer(prices, k);
    }
};