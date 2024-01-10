#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k);

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}


vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    deque<long long int> flag1;
    vector<long long int> flag2;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            flag1.push_back(i);
        }
    }
    if (flag1.size() > 0)
    {
        flag2.push_back(A[flag1.front()]);
    }
    else
    {
        flag2.push_back(0);
    }

    for (int i = K; i < N; i++)
    {
        if (!flag1.empty() && i - flag1.front() >= K)
        {
            flag1.pop_front();
        }

        if (A[i] < 0)
        {
            flag1.push_back(i);
        }

        if (flag1.size() > 0)
        {
            flag2.push_back(A[flag1.front()]);
        }
        else
        {
            flag2.push_back(0);
        }
    }
    return flag2;
}