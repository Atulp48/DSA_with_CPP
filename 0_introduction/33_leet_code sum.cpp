#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>flag;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j]==target)){
                    flag.push_back(i);
                    flag.push_back(j);    
                }
            }
        }
        return flag;
        
    }
};