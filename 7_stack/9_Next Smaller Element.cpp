#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>store;
    store.push(-1);
    vector<int>data(n);
    for(int j=n-1;j>=0;j--){
        int flag= arr[j];
        while(store.top()>=flag){
            store.pop();
        }
        data[j]=store.top();
        store.push(flag);
    }
    return data;
}