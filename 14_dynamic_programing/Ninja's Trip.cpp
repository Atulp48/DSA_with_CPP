// the problem is solved by recursion and passed all test cases on the code studio

int answer(int n, vector<int> &days, vector<int> &cost, int ind)
{

    if (ind >= n)
    {
        return 0;
    }

    int opt1 = cost[0] + answer(n, days, cost, ind + 1);

    int i;
    for (i = ind; i < n && days[i] < days[ind] + 7; i++)
    {
    }
    int opt2 = cost[1] + answer(n, days, cost, i);

    for (i = ind; i < n && days[i] < days[ind] + 30; i++)
    {
    }
    int opt3 = cost[2] + answer(n, days, cost, i);

    return min(opt1, min(opt2, opt3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    return answer(n, days, cost, 0);
}

// the above problem is solved by the dynamic programing and passed al test case on the code studio

int answer(vector<int> &dp, int n, vector<int> &days, vector<int> &cost, int ind)
{

    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int opt1 = cost[0] + answer(dp, n, days, cost, ind + 1);

    int i;
    for (i = ind; i < n && days[i] < days[ind] + 7; i++)
    {
    }
    int opt2 = cost[1] + answer(dp, n, days, cost, i);

    for (i = ind; i < n && days[i] < days[ind] + 30; i++)
    {
    }
    int opt3 = cost[2] + answer(dp, n, days, cost, i);
    dp[ind] = min(opt1, min(opt2, opt3));
    return dp[ind];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    return answer(dp, n, days, cost, 0);
}

// the above code is written in the following way using while loop instead of the for loop;

int answer(vector<int> &dp, int n, vector<int> &days, vector<int> &cost,
           int ind)
{

    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int opt1 = cost[0] + answer(dp, n, days, cost, ind + 1);

    int i;

    i = ind;
    while (i < n && days[i] < days[ind] + 7)
    {
        i++;
    }

    int opt2 = cost[1] + answer(dp, n, days, cost, i);

    i = ind;
    while (i < n && days[i] < days[ind] + 30)
    {
        i++;
    }
    int opt3 = cost[2] + answer(dp, n, days, cost, i);
    dp[ind] = min(opt1, min(opt2, opt3));
    return dp[ind];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    return answer(dp, n, days, cost, 0);
}

// the above problem is solved by the tabulation method  with dynamic progrming and passed all test cases

int answer(int n, vector<int> &days, vector<int> &cost)
{

    vector<int> dp(n + 1, INT_MAX);

    dp[n] = 0;

    for (int x = n - 1; x >= 0; x--)
    {
        int opt1 = cost[0] + dp[x + 1];

        int i;

        i = x;
        while (i < n && days[i] < days[x] + 7)
        {
            i++;
        }

        int opt2 = cost[1] + dp[i];

        i = x;
        while (i < n && days[i] < days[x] + 30)
        {
            i++;
        }
        int opt3 = cost[2] + dp[i];
        dp[x] = min(opt1, min(opt2, opt3));
    }

    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    return answer(n, days, cost);
}