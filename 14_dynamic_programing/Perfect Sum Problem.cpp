//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

private:
    int cons = 1e9 + 7;

    int answer(int arr[], int n, int sum, vector<vector<int>> &dp)
    {

        if (n == 0 && sum == 0)
        {
            return 1;
        }

        if (n == 0)
        {
            return 0;
        }

        if (dp[n][sum] != -1)
        {
            return dp[n][sum] % cons;
        }

        if (arr[n - 1] <= sum)
        {
            dp[n][sum] = (answer(arr, n - 1, sum - arr[n - 1], dp) % cons + answer(arr, n - 1, sum, dp) % cons) % cons;
        }

        else
        {
            dp[n][sum] = answer(arr, n - 1, sum, dp) % cons;
        }

        return dp[n][sum];
    }

public:
    int perfectSum(int arr[], int n, int sum)
    {

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return answer(arr, n, sum, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends