// the problem is solved  by the dynamic programing with the help of memoization method

class Solution
{
    vector<vector<int>> dp;

private:
    int answer(string a, string b, int i, int j)
    {

        if (i == a.length())
        {
            return b.length() - j;
        }
        if (j == b.length())
        {
            return a.length() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int result = 0;

        if (a[i] == b[j])
        {
            return answer(a, b, i + 1, j + 1);
        }
        else
        {

            int ins = 1 + answer(a, b, i, j + 1);
            int del = 1 + answer(a, b, i + 1, j);
            int rep = 1 + answer(a, b, i + 1, j + 1);

            result = min(ins, min(del, rep));
        }

        return dp[i][j] = result;
    }

public:
    int minDistance(string word1, string word2)
    {
        dp.resize(word1.size(), vector<int>(word2.size(), -1));
        return answer(word1, word2, 0, 0);
    }
};

// the problem is solved with the help of the dynamic programing and use tabulation method

class Solution
{

private:
    int answer(string a, string b)
    {

        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = 0; i < a.length(); i++)
        {
            dp[i][b.length()] = a.length() - i;
        }

        for (int j = 0; j < b.length(); j++)
        {
            dp[a.length()][j] = b.length() - j;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int result = 0;
                if (a[i] == b[j])
                {
                    result = dp[i + 1][j + 1];
                }
                else
                {
                    int ins = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int rep = 1 + dp[i + 1][j + 1];
                    result = min(ins, min(del, rep));
                }
                dp[i][j] = result;
            }
        }

        return dp[0][0];
    }

public:
    int minDistance(string word1, string word2)
    {

        return answer(word1, word2);
    }
};

// the problem solved with the help of the dynamic programing and used the space optimization method

class Solution
{

private:
    int answer(string a, string b)
    {

        vector<int> curr(b.size() + 1, 0);
        vector<int> next(b.size() + 1, 0);

        for (int j = 0; j < b.length(); j++)
        {
            next[j] = b.length() - j;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                curr[b.length()] = a.length() - i;
                int result = 0;
                if (a[i] == b[j])
                {
                    result = next[j + 1];
                }
                else
                {
                    int ins = 1 + curr[j + 1];
                    int del = 1 + next[j];
                    int rep = 1 + next[j + 1];
                    result = min(ins, min(del, rep));
                }
                curr[j] = result;
            }
            next = curr;
        }

        return curr[0];
    }

public:
    int minDistance(string word1, string word2)
    {
        if (word1.size() == 0)
        {
            return word2.size();
        }
        if (word2.size() == 0)
        {
            return word1.size();
        }
        return answer(word1, word2);
    }
};