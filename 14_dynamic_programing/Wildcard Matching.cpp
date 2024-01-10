// dynamic programing and used memoization  method and zero based indexing

class Solution
{

    vector<vector<int>> dp;

private:
    bool answer(string &s, string &p, int i, int j)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if ((i >= 0 && j < 0))
        {
            return false;
        }

        if ((i < 0 && j >= 0))
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = answer(s, p, i - 1, j - 1);
        }
        else if (p[j] == '*')
        {
            return dp[i][j] = (answer(s, p, i - 1, j) || answer(s, p, i, j - 1));
        }
        else
        {
            return false;
        }
    }

public:
    bool isMatch(string s, string p)
    {
        dp.resize(s.size(), vector<int>(p.size(), -1));
        return answer(s, p, s.size() - 1, p.size() - 1);
    }
};

// dynamic programing and used memoization method and one based indexing

class Solution
{

    vector<vector<int>> dp;

private:
    bool answer(string &s, string &p, int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return true;
        }
        if ((i > 0 && j == 0))
        {
            return false;
        }

        if ((i == 0 && j > 0))
        {
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        {
            return dp[i][j] = answer(s, p, i - 1, j - 1);
        }
        else if (p[j - 1] == '*')
        {
            return dp[i][j] = (answer(s, p, i - 1, j) || answer(s, p, i, j - 1));
        }
        else
        {
            return false;
        }
    }

public:
    bool isMatch(string s, string p)
    {
        dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return answer(s, p, s.size(), p.size());
    }
};

// dynamic programing  with tabulation method

class Solution
{

private:
    bool answer(string &s, string &p)
    {

        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));

        dp[0][0] = true;

        for (int j = 1; j <= p.size(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }

public:
    bool isMatch(string s, string p)
    {
        return answer(s, p);
    }
};

// dynamic programing used space optimization method

class Solution
{

private:
    bool answer(string &s, string &p)
    {

        vector<int> prev(p.size() + 1, 0);
        vector<int> curr(p.size() + 1, 0);
        prev[0] = true;

        for (int j = 1; j <= p.size(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    curr[j] = (prev[j] || curr[j - 1]);
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[p.size()];
    }

public:
    bool isMatch(string s, string p)
    {
        return answer(s, p);
    }
};