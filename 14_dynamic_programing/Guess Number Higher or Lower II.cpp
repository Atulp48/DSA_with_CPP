// the problem is solved using dynamic programming and memoization methods


class Solution {

vector<vector<int>>dp;
 private:

 int answer(int beg,int end){

 if(beg>=end){
     return 0;
 }

 if(dp[beg][end]!=-1){
     return dp[beg][end];
 }

 int mn=INT_MAX;

 for(int i=beg;i<=end;i++){

mn=min(mn,i+max(answer(beg,i-1),answer(i+1,end)));

 }

 return  dp[beg][end]=mn;

 }  

public:
    int getMoneyAmount(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return  answer(1,n);
    }
};




// the problem is solved using dynamic programming and memoization methods


class Solution {

;
 private:

 int answer(int n){

vector<vector<int>>dp(n+2,vector<int>(n+2,0));

for(int beg=n;beg>=1;beg--){
    for(int end=beg;end<=n;end++){
     
     if(beg==end){
         continue;
     }
     else{
        int mn=INT_MAX;
        for(int i=beg;i<=end;i++){
        mn=min(mn,i+max(dp[beg][i-1],dp[i+1][end]));
     }
     dp[beg][end]=mn;
    }
  }
}
 return  dp[1][n] ;
}  

public:
    int getMoneyAmount(int n) {
        return  answer(n);
    }
};




