#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int A[120];
    int size;

    heap()
    {
        A[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int point = size;
        A[point] = val;
        while (point > 1)
        {
            int root = point / 2;

            if (A[root] < A[point])
            {
                swap(A[root], A[point]);
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void deleted()
    {
        if (size == 0)
        {
            cout << " deletion operation can not be perfomed " << endl;
            return;
        }
        A[1] = A[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftpoint, rightpoint;
            rightpoint = 2 * i + 1;
            leftpoint = 2 * i;

            if (leftpoint < size && A[i] < A[leftpoint])
            {
                swap(A[i], A[leftpoint]);
                i = leftpoint;
            }

            else if (rightpoint < size && A[i] < A[rightpoint])
            {
                swap(A[i], A[rightpoint]);
                i = rightpoint;
            }
            else
            {
                return;
            }
        }
    }
};

void Heapify(int A[], int index, int n)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= n && A[largest] < A[left])
    {
        largest = left;
    }

    if (right <= n && A[largest] < A[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(A[largest], A[index]);
        Heapify(A, largest, n);
    }
}

void heapshort(int A[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(A[size], A[1]);
        size--;

        Heapify(A, 1, size);
    }
}

int main()
{
    heap problem;
    problem.insert(50);
    problem.insert(55);
    problem.insert(53);
    problem.insert(52);
    problem.insert(54);

    problem.print();
    problem.deleted();
    problem.print();

    int A[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        Heapify(A, i, n);
    }

    cout << "the final array is" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    heapshort(A, n);

    cout << "array after the performing the heap short operation is" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "we use the priority queue for solving the porblem" << endl;
    priority_queue<int> flag;

    flag.push(5);
    flag.push(2);
    flag.push(3);
    flag.push(6);
    flag.push(10);

    cout << "the size of the queue is in max heap " << flag.size() << endl;
    cout << "the element that exist at the top is in max heap  " << flag.top() << endl;
    flag.pop();
    cout << "the element that exist at the top is in max heap " << flag.top() << endl;


    priority_queue<int,vector<int>,greater<int>>flag1;

     flag1.push(5);
    flag1.push(2);
    flag1.push(3);
    flag1.push(6);
    flag1.push(10);

    cout << "the size of the queue is in min heap " << flag1.size() << endl;
    cout << "the element that exist at the top is in min heap  " << flag1.top() << endl;
    flag1.pop();
    cout << "the element that exist at the top is in min heap  " << flag1.top() << endl;

    return 0;
}
