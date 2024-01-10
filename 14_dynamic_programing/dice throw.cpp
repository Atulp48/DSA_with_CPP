// the following problem is solved with the help of the dynamic programing and  top to down approach

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    vector<vector<long long>> dp;

private:
    long long answer(int face, int dice, int target)
    {

        if ((target < 0) || (target != 0 && dice == 0) || (target == 0 && dice != 0))
        {
            return 0;
        }

        if (target == 0 && dice == 0)
        {
            return 1;
        }

        if (dp[dice][target] != -1)
        {
            return dp[dice][target];
        }

        long long result = 0;
        for (int i = 1; i <= face; i++)
        {
            result = result + answer(face, dice - 1, target - i);
        }

        dp[dice][target] = result;

        return dp[dice][target];
    }

public:
    long long noOfWays(int M, int N, int X)
    {
        dp.resize(N + 1, vector<long long>(X + 1, -1));
        return answer(M, N, X);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends

// the above problem is solved with the help of the  dynamic programing and solved with the help of the tabulation method

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    vector<vector<long long>> dp;

private:
    long long answer(int face, int dice, int target)
    {

        dp.resize(dice + 1, vector<long long>(target + 1, 0));

        dp[0][0] = 1;

        for (int d = 1; d <= dice; d++)
        {
            for (int t = 1; t <= target; t++)
            {

                long long result = 0;
                for (int i = 1; i <= face; i++)
                {
                    if (t >= i)
                    {
                        result = result + dp[d - 1][t - i];
                    }
                }
                dp[d][t] = result;
            }
        }

        return dp[dice][target];
    }

public:
    long long noOfWays(int M, int N, int X)
    {

        return answer(M, N, X);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends

// the above problem is solved with the help of the dynamic programig and space optimization method

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

private:
    long long answer(int face, int dice, int target)
    {

        vector<long long> curr(target + 1, 0);
        vector<long long> next(target + 1, 0);

        curr[0] = 1;

        for (int d = 1; d <= dice; d++)
        {
            for (int t = 1; t <= target; t++)
            {

                long long result = 0;
                for (int i = 1; i <= face; i++)
                {
                    if (t >= i)
                    {
                        result = result + curr[t - i];
                    }
                }
                next[t] = result;
            }
            curr = next;
        }

        return curr[target];
    }

public:
    long long noOfWays(int M, int N, int X)
    {

        return answer(M, N, X);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends