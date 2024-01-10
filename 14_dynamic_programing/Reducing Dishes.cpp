// the problem is solved with the help of the dynamic programing  and used tabulation method

class Solution
{

    vector<vector<int>> dp;

    int answer(int time, int ind, vector<int> &satisfaction)
    {
        if (ind == satisfaction.size())
        {
            return 0;
        }

        if (dp[ind][time] != -1)
        {
            return dp[ind][time];
        }

        int include = satisfaction[ind] * (time + 1) + answer(time + 1, ind + 1, satisfaction);
        int exclude = answer(time, ind + 1, satisfaction);
        dp[ind][time] = max(include, exclude);
        return dp[ind][time];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int size = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        dp.resize(size + 1, vector<int>(size + 1, -1));
        return answer(0, 0, satisfaction);
    }
};

//  the above porblem  is solved with the help of the dynamic programing and  tabulation method (bottom up apprach)

class Solution
{

    int answer(vector<int> &satisfaction)
    {

        int size = satisfaction.size();

        vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

        for (int ind = size - 1; ind >= 0; ind--)
        {
            for (int time = ind; time >= 0; time--)
            {
                int include = satisfaction[ind] * (time + 1) + dp[ind + 1][time + 1];
                int exclude = dp[ind + 1][time];
                dp[ind][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());

        return answer(satisfaction);
    }
};

// the above problem is solved with the help of the dynamic programing and  space optimization method

class Solution
{

    int answer(vector<int> &satisfaction)
    {

        int size = satisfaction.size();

        vector<int> curr(size + 1, 0);
        vector<int> next(size + 1, 0);

        for (int ind = size - 1; ind >= 0; ind--)
        {
            for (int time = ind; time >= 0; time--)
            {
                int include = satisfaction[ind] * (time + 1) + next[time + 1];
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return curr[0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());

        return answer(satisfaction);
    }
};