#include <bits/stdc++.h>

class Solution
{
public:
    int answer(vector<int> &store, vector<int> &cost, int size)
    {
        int result;
        if (size == 0)
        {
            return cost[0];
        }
        if (size == 1)
        {
            return cost[1];
        }

        if (store[size] != -1)
        {
            return store[size];
        }

        store[size] = min(answer(store, cost, size - 1), answer(store, cost, size - 2)) + cost[size];
        return store[size];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        int result;
        vector<int> store(size + 1, -1);

        result = min(answer(store, cost, size - 1), answer(store, cost, size - 2));
        return result;
    }
};

// following method are used for better understanding of DP and the following code does run but exeed time limit
//  the above code is written by the help of the following code  for bettet solution

class Solution
{
public:
    int answer(vector<int> &cost, int size)
    {
        int result;
        if (size == 0)
        {
            return cost[0];
        }
        if (size == 1)
        {
            return cost[1];
        }
        result = min(answer(cost, size - 1), answer(cost, size - 2)) + cost[size];
        return result;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        int result;

        result = min(answer(cost, size - 1), answer(cost, size - 2));
        return result;
    }
};

//  the following code is used tabulation method (botom up approach )  and successfully run on leet code problem

class Solution
{
public:
    int answer(vector<int> &cost, int size)
    {
        vector<int> store(size + 1);

        store[0] = cost[0];
        store[1] = cost[1];

        for (int i = 2; i < size; i++)
        {
            store[i] = cost[i] + min(store[i - 1], store[i - 2]);
        }
        return min(store[size - 1], store[size - 2]);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        return answer(cost, size);
    }
};

// this solution is used for reduced the space complexity  and run successfully on leet code intrepetor;

class Solution
{
public:
    int answer(vector<int> &cost, int size)
    {

        int val1, val2, val;
        val2 = cost[0];
        val1 = cost[1];

        for (int i = 2; i < size; i++)
        {
            val = cost[i] + min(val1, val2);
            val2 = val1;
            val1 = val;
        }
        return min(val1, val2);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        return answer(cost, size);
    }
};