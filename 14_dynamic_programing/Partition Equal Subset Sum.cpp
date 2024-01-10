// the problem is solved with the help of the dynamic programing and use mamoization method

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    vector<vector<int>> dp;

    bool solve(int target, int arr[], int ind, int size)
    {

        if (ind >= size || target < 0)
        {
            return 0;
        }

        if (target == 0)
        {
            return 1;
        }

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        bool include = solve(target - arr[ind], arr, ind + 1, size);
        bool exclude = solve(target, arr, ind + 1, size);

        dp[ind][target] = include || exclude;

        return dp[ind][target];
    }

public:
    int equalPartition(int N, int arr[])

    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {

            sum = sum + arr[i];
        }
        int target = sum / 2;
        dp.resize(N, vector<int>(target + 1, -1));

        if (!(sum & 1))
        {
            return solve(target, arr, 0, N);
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends

// the problem is solved with the help of the dynamic programing and used tabulation method

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    bool solve(int target, int arr[], int size)
    {

        vector<vector<int>> dp(size + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= size; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = size - 1; i >= 0; i--)
        {
            for (int t = 0; t <= target; t++)
            {
                bool include = false;

                if (t >= arr[i])
                {
                    include = dp[i + 1][t - arr[i]];
                }

                bool exclude = dp[i + 1][t];

                dp[i][t] = include || exclude;
            }
        }

        return dp[0][target];
    }

public:
    int equalPartition(int N, int arr[])

    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {

            sum = sum + arr[i];
        }
        int target = sum / 2;

        if (!(sum & 1))
        {
            return solve(target, arr, N);
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends

// the above problem is solved with the help of the dynamic programing and used the space optamization method

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    bool solve(int target, int arr[], int size)
    {

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int i = size - 1; i >= 0; i--)
        {
            for (int t = 0; t <= target; t++)
            {
                bool include = false;

                if (t >= arr[i])
                {
                    include = next[t - arr[i]];
                }

                bool exclude = next[t];

                curr[t] = include || exclude;
            }
            next = curr;
        }

        return curr[target];
    }

public:
    int equalPartition(int N, int arr[])

    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {

            sum = sum + arr[i];
        }
        int target = sum / 2;

        if (!(sum & 1))
        {
            return solve(target, arr, N);
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends