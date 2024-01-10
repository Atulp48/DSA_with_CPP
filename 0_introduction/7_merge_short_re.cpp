#include <iostream>
using namespace std;

void merg(int *A, int s, int n)
{
    int mid = s + (n - s) / 2;
    int L1 = mid - s + 1;
    int L2 = n - mid;
    int *A1 = new int[L1];
    int *A2 = new int[L2];

    int ind = s;
    for (int i = 0; i < L1; i++)
    {
        A1[i] = A[ind++];
    }

    ind = mid + 1;
    for (int i = 0; i < L2; i++)
    {
        A2[i] = A[ind++];
    }

    int indx1 = 0, indx2 = 0;
    ind = s;

    while (indx1 < L1 && indx2 < L2)
    {
        if (A1[indx1] < A2[indx2])
        {
            A[ind++] = A1[indx1++];
        }
        else
        {
            A[ind++] = A2[indx2++];
        }
    }
    
    while (indx1 < L1)
    {
        A[ind++] = A1[indx1++];
    }

    while (indx2 < L2)
    {
        A[ind++] = A2[indx2++];
    }

    delete []A1;
    delete []A2;
}

void mergS(int *A, int s, int n)
{
    int mid = s + (n - s) / 2;
    if (s >= n)
    {
        return;
    }
    mergS(A, s, mid);

    mergS(A, mid + 1, n);

    merg(A, s, n);
}


int main()
{
    int A[] = {8, 5, 7, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);

    mergS(A, 0, n-1);

    for (int i = 0; i < n ; i++)
    {
        cout << A[i] << "  ";
    }
    return 0;  
}