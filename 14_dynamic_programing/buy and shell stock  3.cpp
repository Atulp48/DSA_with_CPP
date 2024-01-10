//  with the help of dynamic programing  by memoization method

class Solution
{

    vector<vector<vector<int>>> dp;

private:
    int answer(int ind, int buy, vector<int> &prices, int lim)
    {

        if (ind == prices.size())
        {
            return 0;
        }

        if (lim == 0)
        {
            return 0;
        }

        if (dp[ind][buy][lim] != -1)
        {
            return dp[ind][buy][lim];
        }

        int profit = 0;

        if (buy)
        {
            profit = max((-prices[ind] + answer(ind + 1, 0, prices, lim)), (0 + answer(ind + 1, 1, prices, lim)));
        }

        else
        {
            profit = max((+prices[ind] + answer(ind + 1, 1, prices, lim - 1)), (0 + answer(ind + 1, 0, prices, lim)));
        }

        return dp[ind][buy][lim] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return answer(0, 1, prices, 2);
    }
};

// with the help of dynamic programing  by tabulation method

class Solution
{

private:
    int answer(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int lim = 1; lim <= 2; lim++)
                {
                    int profit = 0;

                    if (buy)
                    {
                        profit = max((-prices[ind] + dp[ind + 1][0][lim]), (0 + dp[ind + 1][1][lim]));
                    }
                    else
                    {
                        profit = max((+prices[ind] + dp[ind + 1][1][lim - 1]), (0 + dp[ind + 1][0][lim]));
                    }
                    dp[ind][buy][lim] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return answer(prices);
    }
};

// with the help of dynamic programing  by space optimation method method

class Solution
{
public:
    int answer(vector<int> &prices)
    {
        int size = prices.size();

        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int ind = size - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {

                    int profit = 0;

                    if (buy)
                    {
                        int must_buy = next[0][limit] - prices[ind];
                        int must_skip = next[1][limit];
                        profit = max(must_skip, must_buy);
                    }
                    else
                    {
                        int must_shell = next[1][limit - 1] + prices[ind];
                        int must_skipped = next[0][limit];
                        profit = max(must_skipped, must_shell);
                    }

                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int> &prices)
    {
        return answer(prices);
    }
};