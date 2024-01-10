#include <stack>
class SpecialStack
{
    stack<int> n;
    int flag;

public:
    void push(int data)
    {
        if (n.empty())
        {
            n.push(data);
            flag = data;
        }
        else
        {
            if (flag > data)
            {
                n.push(2 * data - flag);
                flag = data;
            }
            else
            {
                n.push(data);
            }
        }
    }

    int pop()
    {
        int flag2 = n.top();
        if (n.empty())
        {
            return -1;
        }
        n.pop();
        if (flag2 > flag)
        {
            return flag2;
        }
        else
        {
            int flag3 = flag;
            int val = 2 * flag - flag2;
            flag = val;
            return flag3;
        }
    }

    int top()
    {
        if (n.empty())
        {
            return -1;
        }

        int curr = n.top();
        if (curr < flag)
        {
            return flag;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() { return n.empty(); }

    int getMin()
    {
        if (n.empty())
        {
            return -1;
        }
        return flag;
    }
};