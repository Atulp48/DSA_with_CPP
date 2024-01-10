class Solution
{

private:
    int longestSubsequence(int n, vector<vector<int>> &a)
    {
        vector<int> ans;
        ans.push_back(a[0][1]);
        for (int i = 1; i < n; i++)
        {
            if (ans.back() < a[i][1])
            {
                ans.push_back(a[i][1]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i][1]) - ans.begin();
                ans[index] = a[i][1];
            }
        }
        return ans.size();
    }
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        return longestSubsequence(envelopes.size(), envelopes);
    }
};