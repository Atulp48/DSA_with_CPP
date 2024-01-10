// the problem solved by recursion but not run on code studio because of the time limit exceed

#include <bits/stdc++.h>
#define check 1000000007

int sum(int x, int y)
{

    return (x % check + y % check) % check;
}

int mul(int x, int y)
{
    return ((x % check) * 1LL * (y % check)) % check;
}

int answer(int n, int k)
{
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return sum(k, mul(k, k - 1));
    }
    int result = sum(mul(answer(n - 2, k), k - 1), mul(answer(n - 1, k), k - 1));
    return result;
}
int numberOfWays(int n, int k)
{
    // Write your code here.
    return answer(n, k);
}

// the above probelm is solved by the dynamic programing  and the following code is run at code studio

#include <bits/stdc++.h>
#define check 1000000007

int sum(int x, int y)
{

    return (x % check + y % check) % check;
}

int mul(int x, int y)
{
    return ((x % check) * 1LL * (y % check)) % check;
}

int answer(vector<int> &store, int n, int k)
{
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return sum(k, mul(k, k - 1));
    }

    if (store[n] != -1)
    {
        return store[n];
    }

    store[n] = sum(mul(answer(store, n - 2, k), k - 1), mul(answer(store, n - 1, k), k - 1));
    return store[n];
}
int numberOfWays(int n, int k)
{
    // Write your code here.
    vector<int> store(n + 1, -1);
    return answer(store, n, k);
}

// the  above problem is solved by the tabulation method in the following code

#include <bits/stdc++.h>
#define check 1000000007

int sum(int x, int y)
{

    return (x % check + y % check) % check;
}

int mul(int x, int y)
{
    return ((x % check) * 1LL * (y % check)) % check;
}

int answer(int n, int k)
{

    vector<int> store(n + 1, -1);

    store[1] = k;

    store[2] = sum(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        store[i] = sum(mul(store[i - 2], k - 1), mul(store[i - 1], k - 1));
    }
    return store[n];
}
int numberOfWays(int n, int k)
{
    // Write your code here.

    return answer(n, k);
}

//  the following method are used to reduced the space usage

#include <bits/stdc++.h>
#define check 1000000007

int sum(int x, int y)
{

    return (x % check + y % check) % check;
}

int mul(int x, int y)
{
    return ((x % check) * 1LL * (y % check)) % check;
}

int answer(int n, int k)
{

    int val2 = k;

    int val1 = sum(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int val = sum(mul(val2, k - 1), mul(val1, k - 1));
        val2 = val1;
        val1 = val;
    }
    return val1;
}
int numberOfWays(int n, int k)
{
    // Write your code here.

    return answer(n, k);
}
