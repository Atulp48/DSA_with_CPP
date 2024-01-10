// the  0 1 knap sack problem solved by recursion for understanding and dry run but not passed all test case because
//  of the time limit exceed  in following code

#include <bits/stdc++.h>

int answer(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    int collect = 0;
    int left;
    int result;
    if (n == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        return 0;
    }

    if (weight[n] <= maxWeight)
    {
        collect = answer(weight, value, n - 1, maxWeight - weight[n]) + value[n];
    }

    left = answer(weight, value, n - 1, maxWeight);
    result = max(left, collect);
    return result;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    return answer(weight, value, n - 1, maxWeight);
}

//  the above problem solved by the dynamic programing  in the following code
// and passed all test cases on code

#include <bits/stdc++.h>

int answer(vector<vector<int>> &store, vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    int collect = 0;
    int left = 0;
    if (n == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        return 0;
    }

    if (store[n][maxWeight] != -1)
    {
        return store[n][maxWeight];
    }

    if (weight[n] <= maxWeight)
    {
        collect = answer(store, weight, value, n - 1, maxWeight - weight[n]) + value[n];
    }

    left = answer(store, weight, value, n - 1, maxWeight);
    store[n][maxWeight] = max(left, collect);
    return store[n][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> store(n, vector<int>(maxWeight + 1, -1));

    return answer(store, weight, value, n - 1, maxWeight);
}

// the problem soved by the tabulation method by the help of the dynamic programing

#include <bits/stdc++.h>

int answer(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{

    vector<vector<int>> store(n, vector<int>(maxWeight + 1, 0));

    for (int i = weight[0]; i <= maxWeight; i++)
    {

        if (weight[0] <= maxWeight)
        {
            store[0][i] = value[0];
        }
        else
        {
            store[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        int collect = 0;
        int left = 0;
        for (int j = 0; j <= maxWeight; j++)
        {

            if (weight[i] <= j)
            {
                collect = store[i - 1][j - weight[i]] + value[i];
            }

            left = store[i - 1][j];

            store[i][j] = max(left, collect);
        }
    }

    return store[n - 1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    return answer(weight, value, n, maxWeight);
}

// THE ABOVE CODE IS SOLVED BY  FOLLOWING STEP

#include <bits/stdc++.h>

int answer(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{

    vector<int> val1(maxWeight + 1, 0);

    for (int i = weight[0]; i <= maxWeight; i++)
    {

        if (weight[0] <= maxWeight)
        {
            val1[i] = value[0];
        }
        else
        {
            val1[i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = maxWeight; j >= 0; j--)
        {
            int collect = 0;
            int left = 0;

            if (weight[i] <= j)
            {
                collect = val1[j - weight[i]] + value[i];
            }

            left = val1[j];

            val1[j] = max(left, collect);
        }
    }

    return val1[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    return answer(weight, value, n, maxWeight);
}