#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	
	vector<int>result;
	int size=arr.size();

	for(int i=0;i<size;i++){
		int temp=0;
		for(int j=i;j<size;j++){
			temp+=arr[j];
			result.push_back(temp);
		}
	}
	sort(result.begin(),result.end());
	return result[result.size()-k];
}



// second method by using heap  of the datastructure



#include<bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int,vector<int>,greater<int> >flag;
	int size=arr.size();

	for(int i=0;i<size;i++){
		int temp=0;
		for(int j=i;j<size;j++){

         temp+=arr[j];

			if(flag.size()<k){
				flag.push(temp);
			}
			else if(flag.top()<temp){
				flag.pop();
				flag.push(temp);
			}
		}
	}
	return flag.top();
}