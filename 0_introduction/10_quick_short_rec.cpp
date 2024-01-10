#include <iostream>
using namespace std;

int Pt(int *A, int s, int n)
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

void qS(int *A, int s, int n)
{
    if (s >= n)
    {
        return;
    }
    int p = Pt(A, s, n);
    qS(A, s, p - 1);
    qS(A, p + 1, n);
}

int main()
{
    int A[] = {8, 5, 7, 99, 1,77,11,94,1103};
    int n = sizeof(A) / sizeof(A[0]);

    qS(A, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    return 0;
}