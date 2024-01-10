// this code is not passed all test case for the problem its only for understanding of the recursive solution

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
private:
    int answer(int n)
    {
        int result = n;

        if (n == 0)
        {
            return 0;
        }

        for (int i = 1; i * i < n; i++)
        {
            result = min(result, 1 + answer(n - (i * i)));
        }
        return result;
    }

public:
    int MinSquares(int n)
    {

        return answer(n);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// this solution is solved with the help of the dynamic programing and passed all test cases

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
private:
    int answer(vector<int> &dp, int n)
    {

        int result = n;

        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        for (int i = 1; i * i <= n; i++)
        {
            result = min(result, 1 + answer(dp, n - (i * i)));
        }
        dp[n] = result;
        return dp[n];
    }

public:
    int MinSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return answer(dp, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// the problem is solved by the tabulation method with the help of the dynamic progaraming

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int answer(int n)
    {

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i * i <= n; i++)
            {
                if (j >= (i * i))
                {
                    dp[j] = min(dp[j], dp[j - (i * i)] + 1);
                }
            }
        }
        return dp[n];
    }

public:
    int MinSquares(int n)
    {

        return answer(n);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends