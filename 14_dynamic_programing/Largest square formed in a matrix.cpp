//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int answer(vector<vector<int>> mat, int rw, int cl, int &ans)
    {
        if (rw >= mat.size() || cl >= mat[0].size())
        {
            return 0;
        }

        int right = answer(mat, rw, cl + 1, ans);
        int down = answer(mat, rw + 1, cl, ans);
        int dignl = answer(mat, rw + 1, cl + 1, ans);

        if (mat[rw][cl] == 1)
        {
            int val = min(right, min(down, dignl)) + 1;
            ans = max(ans, val);
            return ans;
        }
        return 0;
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;
        int rw = 0;
        int cl = 0;
        answer(mat, rw, cl, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// the following problem is solved by the help of teh dynamci prgraming  and passed all test cases on the GFG

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int answer(vector<vector<int>> &mat, int rw, int cl, int &ans, vector<vector<int>> &dp)
    {
        if (rw >= mat.size() || cl >= mat[0].size())
        {
            return 0;
        }

        if (dp[rw][cl] != -1)
        {
            return dp[rw][cl];
        }

        int right = answer(mat, rw, cl + 1, ans, dp);
        int down = answer(mat, rw + 1, cl, ans, dp);
        int dignl = answer(mat, rw + 1, cl + 1, ans, dp);

        if (mat[rw][cl] == 1)
        {
            dp[rw][cl] = min(right, min(down, dignl)) + 1;
            ans = max(ans, dp[rw][cl]);
            return dp[rw][cl];
        }
        return dp[rw][cl] = 0;
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        answer(mat, 0, 0, ans, dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// the following problem is solved by the help of the dynamic programing  and passed all test case on GFG

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<vector<int>> &mat, int rw, int cl, int &ans)
    {
        if (rw >= mat.size() || cl >= mat[0].size())
        {
            return 0;
        }

        if (dp[rw][cl] != -1)
        {
            return dp[rw][cl];
        }

        int right = answer(mat, rw, cl + 1, ans);
        int down = answer(mat, rw + 1, cl, ans);
        int dignl = answer(mat, rw + 1, cl + 1, ans);

        if (mat[rw][cl] == 1)
        {
            dp[rw][cl] = min(right, min(down, dignl)) + 1;
            ans = max(ans, dp[rw][cl]);
            return dp[rw][cl];
        }
        return dp[rw][cl] = 0;
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;
        dp.resize(n, vector<int>(m, -1));
        answer(mat, 0, 0, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// the problem is solved by the  tabulation method with the help of the  dynamic programing

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int answer(vector<vector<int>> &mat, int &ans)
    {
        int rw = mat.size();
        int cl = mat[0].size();
        vector<vector<int>> dp(rw + 1, vector<int>(cl + 1, 0));

        for (int i = rw - 1; i >= 0; i--)
        {
            for (int j = cl - 1; j >= 0; j--)
            {

                int right = dp[i][j + 1];
                int dignl = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (mat[i][j] == 1)
                {
                    dp[i][j] = min(right, min(down, dignl)) + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;
        answer(mat, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// the problem  is solved by the space optimization method with the help of the dynamic programing

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int answer(vector<vector<int>> &mat, int &ans)
    {
        int rw = mat.size();
        int cl = mat[0].size();
        vector<int> curr(cl + 1, 0);
        vector<int> next(cl + 1, 0);

        for (int i = rw - 1; i >= 0; i--)
        {
            for (int j = cl - 1; j >= 0; j--)
            {

                int right = curr[j + 1];
                int dignl = next[j + 1];
                int down = next[j];

                if (mat[i][j] == 1)
                {
                    curr[j] = min(right, min(down, dignl)) + 1;
                    ans = max(ans, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;
        answer(mat, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends