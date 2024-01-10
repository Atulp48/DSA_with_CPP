#include <iostream>
#include <queue>
using namespace std;

int Solution(int *A, int n, int k)
{

    deque<int> mx(k);
    deque<int> mn(k);

    for (int i = 0; i < k; i++)
    {

        while (!mx.empty() && A[mx.back()] <= A[i])
        {
            mx.pop_back();
        }

        while (!mn.empty() && A[mn.back()] >= A[i])
        {
            mn.pop_back();
        }

        mx.push_back(i);
        mn.push_back(i);
    }
    int flag = 0;
    for (int i = k; i < n; i++)
    {

        flag += A[mx.front()] + A[mn.front()];

        while (!mx.empty() && i - mx.front() >= k)
        {
            mx.pop_front();
        }

        while (!mn.empty() && i - mn.front() >= k)
        {
            mn.pop_front();
        }

        while (!mx.empty() && A[mx.back()] <= A[i])
        {
            mx.pop_back();
        }

        while (!mn.empty() && A[mn.back()] >= A[i])
        {
            mn.pop_back();
        }

        mx.push_back(i);
        mn.push_back(i);
    }

    flag += A[mx.front()] + A[mn.front()];

    return flag;
}

int main()
{

    int A[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << Solution(A, 7, k);
    return 0;
}
