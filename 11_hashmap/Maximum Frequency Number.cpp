#include<bits/stdc++.h>

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int>flag;
    int mx=0;
    int result=0;

    for(int i=0;i<arr.size();i++){
        flag[arr[i]]++; 
        mx=max(mx,flag[arr[i]]);
       
    }

    for(int i=0;i<arr.size();i++){
        if(mx==flag[arr[i]]){
         result=arr[i];
         break;
        }
    }
    return result;
}