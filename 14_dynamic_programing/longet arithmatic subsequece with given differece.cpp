class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int result=0;

        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            int store=0;

            if(dp.count(temp)){
                store=dp[temp];
            }

            dp[arr[i]]=1+store;

            result=max(result,dp[arr[i]]);
        }
         return result;
    }
};

