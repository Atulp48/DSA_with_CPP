
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n,vector<vector<int>> visited, vector<vector<int>> &m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    
        return false;
    

}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string Path)
{

    if (x == n - 1 &&y == n - 1)
    {
        ans.push_back(Path);
        return;
    }

    visited[x][y] = 1;

    int nwx = x + 1;
    int nwy = y;
    if (isSafe(nwx, nwy, n, visited, m))
    {
        Path.push_back('D');
        solve(m, n, ans, nwx, nwy, visited, Path);
        Path.pop_back();
    }

    nwx = x;
    nwy = y - 1;
    if (isSafe(nwx, nwy, n, visited, m))
    {
        Path.push_back('L');
        solve(m, n, ans, nwx, nwy, visited, Path); 
        Path.pop_back();
    } 

    nwx = x;
    nwy = y + 1;
    if (isSafe(nwx, nwy, n, visited, m))
    {
        Path.push_back('R');
        solve(m, n, ans, nwx, nwy, visited, Path);
        Path.pop_back();
    }

    nwx = x - 1;
    nwy = y;
    if (isSafe(nwx, nwy, n, visited, m))
    {
        Path.push_back('U');
        solve(m, n, ans, nwx, nwy, visited, Path);
        Path.pop_back();
    }   

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;

    if (m[0][0] == 0)
    {
        return ans;
    }

    int srx = 0, sry = 0;

    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string Path = "";
    solve(m, n, ans, srx, sry, visited, Path);
    sort(ans.begin(), ans.end());
    return ans;
}


int main()
{
    vector<vector<int>> arr{{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> res;
    res= findPath(arr,4);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}