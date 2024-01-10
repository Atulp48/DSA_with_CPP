// the problem is solved with the help of the dynamic programing and used memoization method

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(int i, int j, string a, string b)
    {

        if (i == a.size() || j == b.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int result = 0;

        if (a[i] == b[j])
        {
            result = 1 + answer(i + 1, j + 1, a, b);
        }
        else
        {
            result = max(answer(i + 1, j, a, b), answer(i, j + 1, a, b));
        }
        return dp[i][j] = result;
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return answer(0, 0, text1, text2);
    }
};

// the problem is solved with the help of the dynamic programing and used  tabulation method method

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(int i, int j, string a, string b)
    {

        dp.resize(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {

                int result = 0;

                if (a[i] == b[j])
                {
                    result = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    result = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = result;
            }
        }
        return dp[0][0];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        return answer(0, 0, text1, text2);
    }
};

// the problem is solved with the help of the dynamic programing and used space optimazation  method

class Solution
{

private:
    int answer(int i, int j, string a, string b)
    {

        vector<int> curr(b.size() + 1, 0);
        vector<int> next(b.size() + 1, 0);

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {

                int result = 0;

                if (a[i] == b[j])
                {
                    result = 1 + next[j + 1];
                }
                else
                {
                    result = max(next[j], curr[j + 1]);
                }
                curr[j] = result;
            }
            next = curr;
        }
        return curr[0];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        return answer(0, 0, text1, text2);
    }
};