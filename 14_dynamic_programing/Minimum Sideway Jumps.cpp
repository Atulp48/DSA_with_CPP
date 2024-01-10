// the problem is solved with the dynamic programing method  and  solved by top - down approach

class Solution
{

    vector<vector<int>> dp;

private:
    int solve(vector<int> &obstacles, int curr_lane, int curr_position)
    {
        int n = obstacles.size() - 1;
        if (curr_position == n)
        {
            return 0;
        }

        if (dp[curr_lane][curr_position] != -1)
        {
            return dp[curr_lane][curr_position];
        }

        if (obstacles[curr_position + 1] != curr_lane)
        {
            return solve(obstacles, curr_lane, curr_position + 1);
        }
        else
        {
            int result = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (curr_lane != i && obstacles[curr_position] != i)
                {
                    result = min(result, solve(obstacles, i, curr_position) + 1);
                }
            }
            dp[curr_lane][curr_position] = result;
            return dp[curr_lane][curr_position];
        }
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        dp.resize(4, vector<int>(obstacles.size(), -1));
        return solve(obstacles, 2, 0);
    }
};

// the above problem is solved with the help of the tabulation method in the following code

class Solution
{

    vector<vector<int>> dp;

private:
    int solve(vector<int> &obstacles)
    {
        dp.resize(4, vector<int>(obstacles.size(), 1e7));
        int n = obstacles.size() - 1;
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int curr_position = n - 1; curr_position >= 0; curr_position--)
        {
            for (int curr_lane = 1; curr_lane <= 3; curr_lane++)
            {

                if (obstacles[curr_position + 1] != curr_lane)
                {
                    dp[curr_lane][curr_position] = dp[curr_lane][curr_position + 1];
                }
                else
                {
                    int result = 1e7;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (curr_lane != i && obstacles[curr_position] != i)
                        {
                            result = min(result, dp[i][curr_position + 1] + 1);
                        }
                    }
                    dp[curr_lane][curr_position] = result;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {

        return solve(obstacles);
    }
};

// the above problem is sovled  by the dynamic programing and  used space optimaziation method

class Solution
{

private:
    int solve(vector<int> &obstacles)
    {
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        int n = obstacles.size() - 1;
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int curr_position = n - 1; curr_position >= 0; curr_position--)
        {
            for (int curr_lane = 1; curr_lane <= 3; curr_lane++)
            {

                if (obstacles[curr_position + 1] != curr_lane)
                {
                    curr[curr_lane] = next[curr_lane];
                }
                else
                {
                    int result = 1e7;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (curr_lane != i && obstacles[curr_position] != i)
                        {
                            result = min(result, next[i] + 1);
                        }
                    }
                    curr[curr_lane] = result;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {

        return solve(obstacles);
    }
};