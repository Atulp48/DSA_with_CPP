class Solution
{

private:
    vector<int> fun1(int n, vector<int> arr)
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

    vector<int> fun2(int n, vector<int> arr)
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

    int largestarea(vector<int> heights)
    {
        int a1 = INT_MIN;
        int store = heights.size();
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxi = INT_MIN;
        vector<int> histogram(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {

            for (int j = 0; j < histogram.size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    histogram[j]++;
                }
                else
                {
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestarea(histogram));
        }
        return maxi;
    }
};