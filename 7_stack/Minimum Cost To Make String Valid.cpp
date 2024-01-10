#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    int d = str.length();
    stack<char> STACK;
    if (d % 2 == 0)
    {
        for (int i = 0; i < d; i++)
        {
            char store = str[i];
            if (store == '{')
            {
                STACK.push(store);
            }
            else
            {
                if (!STACK.empty() && STACK.top() == '{')
                {
                    STACK.pop();
                }
                else
                {
                    STACK.push(store);
                }
            }
        }
        int flag1 = 0, flag2 = 0;
        while (!STACK.empty())
        {
            if (STACK.top() == '}')
            {
                flag1++;
            }
            else
            {
                flag2++;
            }
            STACK.pop();
        }
        return ((flag1 + 1) / 2 + (flag2 + 1) / 2);
    }
    return -1;
}
