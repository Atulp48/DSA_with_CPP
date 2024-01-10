#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> store;
        for (int j = 0; j < n; j++)
        {
            store.push(j);
        }

        while (store.size() > 1)
        {
            int flag1, flag2;
            flag1 = store.top();
            store.pop();
            flag2 = store.top();
            store.pop();
            if (M[flag1][flag2] != 1)
            {
                store.push(flag1);
            }
            else
            {
                store.push(flag2);
            }
        }

        int result = store.top();

        bool r = false;
        bool c = false;
        int r1 = 0, c1 = 0;

        for (int x = 0; x < n; x++)
        {
            if (M[result][x] == 0)
            {
                r1++;
            }
        }

        if (r1 == n)
        {
            r = true;
        }

        for (int x = 0; x < n; x++)
        {
            if (M[x][result] == 1)
            {
                c1++;
            }
        }
        if (c1 == (n - 1))
        {
            c = true;
        }

        if (r == true && c == true)
        {
            return result;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
