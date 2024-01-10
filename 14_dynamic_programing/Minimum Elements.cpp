
//  THE FOLLOWING METHOD IS  COMBINATION OF THE RECURSION AND MEMOIZATION THAT MEANS THE  DYNAMIC  PROGRA

#include <bits/stdc++.h>

int answer(vector<int> &val, int t, vector<int> &store)
{
    if (t == 0)
    {
        return 0;
    }

    if (t < 0)
    {
        return INT_MAX;
    }

    if (store[t] != -1)
    {
        return store[t];
    }

    int mn = INT_MAX;
    for (int i = 0; i < val.size(); i++)
    {
        int temp = answer(val, t - val[i], store);
        if (temp != INT_MAX)
        {
            mn = min(mn, 1 + temp);
        }
    }

    store[t] = mn;

    return mn;
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    //   int size = num.size();
    vector<int> store(x + 1, -1);
    int result = answer(num, x, store);

    if (result == INT_MAX)
    {
        return -1;
    }
    else
    {
        return result;
    }
}

//  THE FOLLOWING METHOD IS USED  FOR THE TABULATION METHOD FORMULA

#include <bits/stdc++.h>

int answer(vector<int> &val, int t)
{

    vector<int> store(t + 1, INT_MAX);
    store[0] = 0;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < val.size(); j++)
        {
            if (i - val[j] >= 0 && store[i - val[j]] != INT_MAX)
            {

                store[i] = min(store[i], 1 + store[i - val[j]]);
            }
        }
    }

    if (store[t] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return store[t];
    }
}

int minimumElements(vector<int> &num, int x) { return answer(num, x); }