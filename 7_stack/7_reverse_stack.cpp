#include<bits/stdc++.h>
using namespace std;
void fun(int flag, stack<int> &stack) {
  if (stack.empty()) {
    stack.push(flag);
    return;
  }
  int flag1 = stack.top();
  stack.pop();
  fun(flag, stack);
  stack.push(flag1);
}

void reverseStack(stack<int> &stack) {
  // Write your code here
  if (stack.empty()) {
    return;
  }
  int flag = stack.top();
  stack.pop();
  reverseStack(stack);
  fun(flag, stack);
}