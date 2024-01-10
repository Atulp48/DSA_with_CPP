#include <bits/stdc++.h>

void answer(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int flag = myStack.top();
    myStack.pop();
    answer(myStack, x);
    myStack.push(flag);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    answer(myStack, x);
    return myStack;
}
