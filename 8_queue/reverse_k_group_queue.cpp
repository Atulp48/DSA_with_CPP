#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}

queue<int> modifyQueue(queue<int> q, int k) {
  
    stack<int>flag;
    int flag2=q.size()-k;
    
    for(int i=0; i<k;i++){
        int flag3=q.front();
       
        flag.push(flag3);
         q.pop();
    }
    
    while(!flag.empty()){
        int flag3=flag.top();
       
        q.push(flag3);
         flag.pop();
    }
    
    while(flag2--){
        int flag3=q.front();
       
        q.push(flag3);
         q.pop();
    }
    return q;
}