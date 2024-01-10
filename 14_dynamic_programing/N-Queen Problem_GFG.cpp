//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

private:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagnol;
    unordered_map<int, bool> lowerLeftDiagnol;
    void storeAns(vector<vector<char>> &board, vector<vector<int>> &ans, int n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[j][i] == 'Q')
                    temp.push_back(j + 1);
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int col, int row, int n)
    {
        if (rowCheck[row])
        {
            return false;
        }
        if (upperLeftDiagnol[n - 1 + col - row])
        {
            return false;
        }
        if (lowerLeftDiagnol[row + col])
        {
            return false;
        }
        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<int>> &ans)
    {
        if (col >= n)
        {
            storeAns(board, ans, n);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(col, row, n))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagnol[n - 1 - row + col] = 1;
                lowerLeftDiagnol[row + col] = 1;
                solve(board, col + 1, n, ans);
                board[row][col] = '.';
                rowCheck[row] = 0;
                upperLeftDiagnol[n - 1 - row + col] = 0;
                lowerLeftDiagnol[row + col] = 0;
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        int col = 0;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, col, n, ans);
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
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends