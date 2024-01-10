#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr, vector<vector<int>> &ans, int index)
{
    if (index >= arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int j = index; j < arr.size(); j++)
    {
        swap(arr[index], arr[j]);
        solve(arr, ans, index + 1);
        swap(arr[index], arr[j]);
    }
}

int main()
{
    vector<vector<int>> ap;
    vector<int> arr{1,2,3};
    solve(arr, ap, 0);
    for(int i=0; i<ap.size(); i++){
        for(int j=0; j<ap[i].size(); j++){
            cout<<ap[i][j]<<" ";
        }
        cout<<endl;
    }
}
