#include <iostream>
using namespace std;

class kQ
{

public:
    int n, k, *A, *F, *R, FR, *nxt;

    kQ(int n, int k)
    {
        this->n = n;
        this->k = k;
        F = new int[k];
        R = new int[k];
        for (int i = 0; i < k; i++)
        {
            F[i] = -1;
            R[i] = -1;
        }

        nxt = new int[n];
        for (int i = 0; i < n; i++)
        {
            nxt[i] = i + 1;
        }
        nxt[n - 1] = -1;

        A = new int[n];
        FR = 0;
    }

    void enq(int data, int qn)
    {
        int indx = FR;

        if (FR == -1)
        {
            cout << "space not allowed" << endl;
            return;
        }
        FR = nxt[indx];
        if (F[qn - 1] == -1)
        {
            F[qn - 1] = indx;
        }
        else
        {
            nxt[R[qn - 1]] = indx;
        }
        nxt[indx] = -1;
        R[qn - 1] = indx;
        A[indx] = data;
    }

    int dq(int qn)
    {
        int indx = F[qn - 1];
        if (F[qn - 1] == -1)
        {
            cout << "empty" << endl;
            return -1;
        }
        F[qn - 1] = nxt[indx];
        nxt[indx] = FR;
        FR = indx;
        return A[indx];
    }
};

int main()
{

kQ q(10,3);
q.enq(10,1);
q.enq( 15,1);
q.enq(20,2);
q.enq(25,1);


cout<<q.dq(1)<<endl;
cout<<q.dq(2)<<endl;
cout<<q.dq(1)<<endl;
cout<<q.dq(1)<<endl;

cout<<q.dq(1)<<endl;


    return 0;
}