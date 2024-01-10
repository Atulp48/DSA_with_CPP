#include <bits/stdc++.h> 
void Heapify(vector<int>&A, int index, int n)
{
    int largest = index;
    int left = 2 * index+1;
    int right = 2 * index + 1+1;

    if (left < n && A[largest] > A[left])
    {
        largest = left;
    }

    if (right < n && A[largest] > A[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(A[largest], A[index]);
        Heapify(A, largest, n);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
      for (int i = n/2-1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
    return arr;
}
