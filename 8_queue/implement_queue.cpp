 #include <bits/stdc++.h>
class Queue {
  int *A, F, R, S;

public:
  Queue() {
    S = 100000;
    A = new int[S];
    F = 0;
    R = 0;
  }

  bool isEmpty() {
    if (F == R) {
      return true;
    } else {
      return false;
    }
  }

  void enqueue(int data) {

    if (R == S) {
      cout << "Queue is Full" << endl;
    } else {
      A[R] = data;
      R = R + 1;
    }
  }

  int dequeue() {

    if (F == R) {
      return -1;
    }

    else {
      int flag = A[F];
      A[F]=-1;
      F = F + 1;
      if (F == R) {
        F = 0;
        R = 0;
      }
      return flag;
    }
  }

  int front() {

    if (F == R) {
      return -1;
    } else {
      return A[F];
    }
  }
};