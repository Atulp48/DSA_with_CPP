#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    int *A, top, s;

    Stack(int s)
    {
        this->s = s;
        A = new int[s];
        top = -1;
    }

    void push(int ele)
    {
        if ((s - top) > 1)
        {
            top++;
            A[top] = ele;
        }
        else
        {
            cout << "overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "pop operation is not possible" << endl;
        }
    }

     int topestelement()
    {
        if (top >= 0)
        {
            return A[top];
        }
        else
        {
            cout << "empty stack" << endl;
             return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack ss(7);
    ss.push(20);
    ss.push(29);
    ss.push(24);
    cout << ss.topestelement() << endl;
    ss.pop();
     cout << ss.topestelement() << endl;
    ss.pop();
     cout << ss.topestelement() << endl;
    ss.pop();
    cout << ss.topestelement() << endl;

    return 0;
}