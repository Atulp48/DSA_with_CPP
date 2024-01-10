// the following code is  passed all test case but other code mentioned below of this code is right but not passed
// all test case  the other code is  for  remember and underestanding of the way of the  solve of the problem

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (ans.back() < a[i])
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends

// the problem is solved with the help of the dynamic programing  and top to down approach

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

private:
    int answer(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        int include = 0;
        if (prev == -1 || a[curr] > a[prev])
        {
            include = 1 + answer(n, a, curr + 1, curr, dp);
        }
        int exclude = answer(n, a, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

public:
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return answer(n, a, 0, -1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends

// the above problem is solved with the help of the dynamic programing and solved with bottom to up approach

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

private:
    int answer(int n, int a[])
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                    include = 1 + dp[curr + 1][curr + 1];

                int exclude = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

public:
    int longestSubsequence(int n, int a[])
    {

        return answer(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends

// the problem is solved with the help of the space optimization method

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

private:
    int answer(int n, int a[])
    {

        vector<int> curr_row(n + 1, 0);
        vector<int> next_row(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                    include = 1 + next_row[curr + 1];

                int exclude = next_row[prev + 1];
                curr_row[prev + 1] = max(include, exclude);
            }
            next_row = curr_row;
        }
        return next_row[0];
    }

public:
    int longestSubsequence(int n, int a[])
    {

        return answer(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
