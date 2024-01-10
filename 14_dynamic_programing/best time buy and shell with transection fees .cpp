class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<int> &prices, int fee)
    {
        int n = prices.size();
        dp.resize(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                int profit = 0;

                if (buy)
                {
                    profit = max((-prices[ind] + dp[ind + 1][0] - fee), (0 + dp[ind + 1][1]));
                }
                else
                {
                    profit = max((+prices[ind] + dp[ind + 1][1]), (0 + dp[ind + 1][0]));
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return answer(prices, fee);
    }
};

//  or

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<int> &prices, int fee)
    {
        int n = prices.size();
        dp.resize(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                int profit = 0;

                if (buy)
                {
                    profit = max((-prices[ind] + dp[ind + 1][0]), (0 + dp[ind + 1][1]));
                }
                else
                {
                    profit = max((+prices[ind] + dp[ind + 1][1] - fee), (0 + dp[ind + 1][0]));
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return answer(prices, fee);
    }
};