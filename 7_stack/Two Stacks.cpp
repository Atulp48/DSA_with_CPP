#include <bits/stdc++.h>
class TwoStack
{

public:
    int *A, t1, t2, shape;
    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        this->shape = s;
        t1 = -1;
        t2 = s;
        A = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if ((t2 - t1) > 1)
        {
            t1++;
            A[t1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if ((t2 - t1) > 1)
        {
            t2--;
            A[t2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (t1 >= 0)
        {
            int flag = A[t1];
            t1--;
            return flag;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (t2 < shape)
        {
            int flag = A[t2];
            t2++;
            return flag;
        }
        else
        {
            return -1;
        }
    }
};
