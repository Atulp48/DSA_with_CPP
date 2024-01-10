// the problem is solved using   recursive methods in dynamic programming language programming but not passing all of the test

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

private:
    int answer(int ind, int diff, int A[])
    {

        if (ind < 0)
        {
            return 0;
        }

        int result = 0;

        for (int j = ind - 1; j >= 0; j--)
        {
            if (A[ind] - A[j] == diff)
            {
                result = max(result, 1 + answer(j, diff, A));
            }
        }

        return result;
    }

public:
    int lengthOfLongestAP(int A[], int n)
    {

        if (n <= 2)
        {
            return n;
        }

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                result = max(result, 2 + answer(i, A[j] - A[i], A));
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends



// the problem is solved with the help of the dynamic programming language with use memoization and  not passed all tests case


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   

    
private:

int answer(int ind, int diff,int A[], unordered_map<int,int>dp[]){
    
    if(ind<0){
        return 0;
    }
    
    if(dp[ind].count(diff)){
        return dp[ind][diff];
    }
    
    int result=0;
    
    for(int j=ind-1;j>=0;j--){
        if(A[ind]-A[j]==diff){
             result=max(result,1+answer(j,diff,A,dp));
        }
    }
    dp[ind][diff]=result;
    
    return dp[ind][diff];
    
    
}
    
public:
    int lengthOfLongestAP(int A[], int n) {
        
        if(n<=2){
         return n;
        }
        
        unordered_map<int,int>dp[n+1];
        
        int result=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                result=max(result,2+answer(i,A[j]-A[i],A,dp));
            }
        }
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


// the problem is solved with the help of the dynamic programming language with use tabulation method and   passed all tests case


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
           if(n==1)return 1;
           
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        int ans=2;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d=arr[j]-arr[i];
                int cnt=2;
                int s=arr[j];
                
                while(mp.find(d+s)!=mp.end())
                {
                    cnt++;
                    s=d+s;
                }
                ans=max(ans,cnt);
            }
            
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

