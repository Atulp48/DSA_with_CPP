#include <bits/stdc++.h> 

void ans(stack<int>&inputStack, int N,int flag){
   if(flag==N/2){
     inputStack.pop();
      return;
   }
    int store=inputStack.top();
    inputStack.pop();
    ans(inputStack,N,flag+1);
    inputStack.push(store);
}

void deleteMiddle(stack<int>&inputStack, int N){
    int flag=0;
    ans(inputStack,N,flag);
}  