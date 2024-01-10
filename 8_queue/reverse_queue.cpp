#include<bits/stdc++.h>
using namespace std;


class Solution
{    
    
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int>n;
        
      while(!q.empty()){
          int flag=q.front();
          q.pop();
          n.push(flag);
          
      }
      while(!n.empty()){
          int flag2=n.top();
          n.pop();
          q.push(flag2);
      }
    
    return q;
    }
};

int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
