#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution
{
private:
    vector<int> fun2(int n, int *arr)
    {

        stack<int> store;
        store.push(-1);
        vector<int> data(n);
        for (int j = 0; j < n; j++)
        {
            int flag = arr[j];
            while (store.top() != -1 && arr[store.top()] >= flag)
            {
                store.pop();
            }
            data[j] = store.top();
            store.push(j);
        }
        return data;
    }

    vector<int> fun1(int n, int *arr)
    {

        stack<int> store;
        store.push(-1);
        vector<int> data(n);
        for (int j = n - 1; j >= 0; j--)
        {
            int flag = arr[j];
            while (store.top() != -1 && arr[store.top()] >= flag)
            {
                store.pop();
            }
            data[j] = store.top();
            store.push(j);
        }
        return data;
    }

    int largestRectangle(int store, int *heights)
    {
        int a1 = INT_MIN;
        vector<int> flag1(store);
        vector<int> flag2(store);
        flag1 = fun1(store, heights);
        flag2 = fun2(store, heights);

        for (int i = 0; i < store; i++)
        {
            int x = heights[i];

            if (flag1[i] == -1)
            {
                flag1[i] = store;
            }
            int y = flag1[i] - flag2[i] - 1;
            int a2 = x * y;
            a1 = max(a1, a2);
        }
        return a1;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {

        int ans1 = largestRectangle(m, M[0]);

        for (int x = 1; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (M[x][y] == 0)
                {
                    M[x][y] = 0;
                }
                else
                {
                    M[x][y] += M[x - 1][y];
                }
            }

            ans1 = max(ans1, largestRectangle(m, M[x]));
        }
        return ans1;
    }
};

int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
