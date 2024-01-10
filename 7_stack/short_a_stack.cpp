#include <bits/stdc++.h>
using namespace std;

void ans(int flag,stack<int> &s) {
  if (!s.empty() && s.top() < flag||s.empty()) {
    s.push(flag);
    return;
  }
  int flag1=s.top();
  s.pop();
  ans(flag,s);
  s.push(flag1);
}

void sortStack(stack<int> &s) {

  if(s.empty()) {
    return;
  }

  int flag = s.top();
  s.pop();
  sortStack(s);
  ans(flag,s);
}
