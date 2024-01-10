#include <bits/stdc++.h>

int check(int x, int y)
{
    if (x > y)
    {
        return 1;
    }
    else if (x == y)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void answer(int A, priority_queue<int> &mxHP,
            priority_queue<int, vector<int>, greater<int>> &mnHP, int &m)
{

    switch (check(mxHP.size(), mnHP.size()))
    {

    case 0:
        if (A > m)
        {
            mnHP.push(A);
            m = mnHP.top();
        }
        else
        {
            mxHP.push(A);
            m = mxHP.top();
        }
        break;

    case 1:
        if (A > m)
        {
            mnHP.push(A);
            m = (mxHP.top() + mnHP.top()) / 2;
        }
        else
        {
            mnHP.push(mxHP.top());
            mxHP.pop();
            mxHP.push(A);
            m = (mxHP.top() + mnHP.top()) / 2;
        }
        break;

    case -1:
        if (A > m)
        {
            mxHP.push(mnHP.top());
            mnHP.pop();
            mnHP.push(A);
            m = (mxHP.top() + mnHP.top()) / 2;
        }
        else
        {

            mxHP.push(A);
            m = (mxHP.top() + mnHP.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{

    int m = 0;
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> mnHP;
    priority_queue<int> mxHP;

    for (int i = 0; i < n; i++)
    {
        answer(arr[i], mxHP, mnHP, m);
        result.push_back(m);
    }
    return result;
}
