
#include <iostream>
using namespace std;

int Pt(vector<int> &A, int s, int n)
{
    int pi = A[s], flag = 0;
    for (int i = s + 1; i <= n; i++)
    {
        if (A[i] < pi)
        {
            flag++;
        }
    }
    int count = flag + s;
    swap(A[count], A[s]);

    int i = s;
    int j = n;

    while (i < count && j > count)
    {
        while (A[i] < A[count])
        {
            i++;
        }
        while (A[j] > A[count])
        {
            j--;
        }

        if (i < count && j > count)
        {
            swap(A[i++], A[j--]);
        }
    }
    return count;
}

void qS(vector<int> &A, int s, int n)
{
    if (s >= n)
    {
        return;
    }
    int p = Pt(A, s, n);
    qS(A, s, p - 1);
    qS(A, p + 1, n);
}

vector<int> quickSort(vector<int> arr)
{
    qS(arr, 0, arr.size() - 1);
    return arr;
}
