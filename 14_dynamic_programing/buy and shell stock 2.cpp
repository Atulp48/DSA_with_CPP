
// we use dynamic programing and use the memoazation method

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<int> &prices)
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
                    profit = max((+prices[ind] + dp[ind + 1][1]), (0 + dp[ind + 1][0]));
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices)
    {

        return answer(prices);
    }
};

// we use dynamic programing and  bottom up approach

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<int> &prices)
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
                    profit = max((+prices[ind] + dp[ind + 1][1]), (0 + dp[ind + 1][0]));
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices)
    {

        return answer(prices);
    }
};

// we use dynamic programing and space optamization method

class Solution
{
private:
    int answer(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                int profit = 0;

                if (buy)
                {
                    profit = max((-prices[ind] + next[0]), (0 + next[1]));
                }
                else
                {
                    profit = max((+prices[ind] + next[1]), (0 + next[0]));
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }

public:
    int maxProfit(vector<int> &prices)
    {

        return answer(prices);
    }
};