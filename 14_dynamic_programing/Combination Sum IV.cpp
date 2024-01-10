// the problem is solved by the recursion for understanding better but not passed all test cases on the
//  code studio

#include <bits/stdc++.h>

int answer(vector<int> &num, int tar)
{
    int result = 0;

    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }

    for (int i = 0; i < num.size(); i++)
    {
        result = result + answer(num, tar - num[i]);
    }
    return result;
}

int findWays(vector<int> &num, int tar)
{

    return answer(num, tar);
}

// the problem is solved by the  dynamic programing  and passed all test cases  on code studio

#include <bits/stdc++.h>

int answer(vector<int> &store, vector<int> &num, int tar)
{
    int result = 0;

    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    if (store[tar] != -1)
    {
        return store[tar];
    }

    for (int i = 0; i < num.size(); i++)
    {
        result = result + answer(store, num, tar - num[i]);
    }
    store[tar] = result;
    return store[tar];
}

int findWays(vector<int> &num, int tar)
{

    vector<int> store(tar + 1, -1);
    return answer(store, num, tar);
}

// the above problem is solved by teh tabulation method in the following code

#include <bits/stdc++.h>

int answer(vector<int> &num, int tar)
{
    vector<int> store(tar + 1, 0);
    store[0] = 1;

    for (int j = 1; j <= tar; j++)
    {
        for (int i = 0; i < num.size(); i++)
        {
            if (j - num[i] >= 0)
            {
                store[j] = store[j] + store[j - num[i]];
            }
        }
    }
    return store[tar];
}

int findWays(vector<int> &num, int tar)
{

    return answer(num, tar);
}
