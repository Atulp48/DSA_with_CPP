#include <bits/stdc++.h>
#define check 1000000007

long long int ans(vector<long long int> &store, int n)
{

    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    if (store[n] != -1)
    {
        return store[n];
    }

    store[n] = ((n - 1) % check) * ((ans(store, n - 1) % check) + (ans(store, n - 2) % check)) % check;

    return store[n];
}

long long int countDerangements(int n)
{
    vector<long long int> store(n + 1, -1);
    return ans(store, n);
}

// the above problem solved by the help of the tabulation method  on the following code

#include <bits/stdc++.h>
#define check 1000000007

long long int ans(int n)
{

    vector<long long int> store(n + 1, 0);
    store[1] = 0;
    store[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int val1 = store[i - 1] % check;
        long long int val2 = store[i - 2] % check;
        long long int val = (val1 + val2) % check;
        long long int result = (val * (i - 1)) % check;
        store[i] = result;
    }

    return store[n];
}

long long int countDerangements(int n)
{
    return ans(n);
}

// the following method  used to utilized space for above code by using less memory

#include <bits/stdc++.h>
#define check 1000000007

long long int ans(int n)
{

    long long int flag1, flag2;
    flag1 = 1;
    flag2 = 0;

    for (int i = 3; i <= n; i++)
    {
        long long int val1 = flag1 % check;
        long long int val2 = flag2 % check;
        long long int val = (val1 + val2) % check;
        long long int result = (val * (i - 1)) % check;
        flag2 = flag1;
        flag1 = result;
    }

    return flag1;
}

long long int countDerangement(int n)
{
    return ans(n);
}