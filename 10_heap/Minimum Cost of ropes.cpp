//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long,vector<long long>,greater<long long> > flag;
        
        for(int i=0;i<n;i++){
            flag.push(arr[i]);
        }
        
        long long ans=0;
        
        while(flag.size()>1){
            long long val1=flag.top();
            flag.pop();
            
             long long val2=flag.top();
            flag.pop();
            
            long long result=val1+val2;
             ans+=result;
             
             flag.push(result);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends