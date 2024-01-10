#include <bits/stdc++.h>
class Deque {
  int *A, F, R, S;

public:
  Deque(int n) {

    S = n;
    A = new int[n];
    F = -1;
    R = -1;
  }

  bool pushFront(int x) {
    if ((F == 0 && R == S - 1) || (F != 0 && R == (F - 1) % (S - 1))) {
      return false;
    } 
    else if (F == -1) {
      F = 0;
      R = 0;

    }
     else if (F == 0 && R != S - 1) {
      F = S - 1;
    } 
    else {
      F = F - 1;
    }
    A[F] = x;
    return true;
  }

  bool pushRear(int x) {

   if ((F == 0 && R == S - 1) || (F != 0 && R == (F - 1) % (S - 1))) {
      return false;
    } 
    else if (F == -1) {
      F = 0;
      R = 0;

    } 
    else if (R == S - 1 && F != 0) {
      R = 0;
    } 
    else {
      R = R + 1;
    }
    A[R] = x;
    return true;
  }

  int popFront() {
    if (F == -1) {
      return -1;
    }
    int flag = A[F];
    A[F] = -1;
    if (F == R) {
      F = -1;
      R = -1;
    }
     else if (F == S - 1) {
      F = 0;
    }
     else {
      F = F + 1;
    }
    return flag;
  }

  int popRear() {
    if (F == -1) {
      return -1;
    }
    int flag = A[R];
    A[R] = -1;
    if (F == R) {
      F = -1;
      R = -1;
    }
     else if (R == 0) {
      R = S - 1;
    }
     else {
      R = R - 1;
    }
    return flag;
  }

  int getFront() {
    if (F == -1) {
      return -1;
    }
    return A[F];
  }

  int getRear() {
    if (F == -1) {
      return -1;
    }
    return A[R];
  }

  bool isEmpty() {
    if (F == -1) {
      return true;
    } else {
      return false;
    }
  }

  bool isFull() {
    if ((F == 0 && R == S - 1) || (F != 0 && R == (F - 1) % (S - 1))) {
      return true;
    } else {
      return false;
    }
  }
};