#include <bits/stdc++.h>
class NStack {
  int *A, *t, *ne, n, s, flag;

public:
  NStack(int N, int S) {
    n = N;
    s = S;
    A = new int[s];
    t = new int[n];
    ne = new int[s];
    for (int i = 0; i < n; i++) {
      t[i] = -1;
    }
    for (int i = 0; i < s; i++) {
      ne[i] = i + 1;
    }
    ne[s - 1] = -1;
    flag = 0;
  }

  bool push(int x, int m) {
    if (flag == -1) {
      return false;
    }
    int ind = flag;
    flag = ne[ind];
    A[ind] = x;
    ne[ind] = t[m - 1];
    t[m - 1] = ind;
    return true;
  }

  int pop(int m) {
    if (t[m - 1] == -1) {
      return -1;
    }
    int ind = t[m - 1];
    t[m - 1] = ne[ind];
    ne[ind] = flag;
    flag = ind;
    return A[ind];
  }
};