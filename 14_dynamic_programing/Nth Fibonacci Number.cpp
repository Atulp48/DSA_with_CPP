#include <bits/stdc++.h>
using namespace std;

int FN(int t, vector<int> &store)
{
    if (t <= 1)
    {
        return t;
    }

    if (store[t] != -1)
    {
        return store[t];
    }
    store[t] = FN(t - 1, store) + FN(t - 2, store);
    return store[t];
}

int main()
{
    /*
     *  Write your code here.
     *  Read input as specified in the question.
     *  Print output as specified in the question.
     */

    int t;
    cin >> t;
    vector<int> store(t + 1);
    for (int i = 0; i <= t; i++)
    {
        store[i] = -1;
    }
    cout << FN(t, store) << endl;

    return 0;
}

// or

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    vector<int> store(t + 1);
    store[0] = 0;
    store[1] = 1;
    for (int i = 2; i <= t; i++)
    {
        store[i] = store[i - 1] + store[i - 2];
    }
    cout << store[t] << endl;

    return 0;
}

// or

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    int store1 = 1;
    int store2 = 0;

    if (t == 0)
    {
        return store2;
    }

    for (int i = 2; i <= t; i++)
    {
        int store = store2 + store1;
        store2 = store1;
        store1 = store;
    }

    cout << store1 << endl;

    return 0;
}