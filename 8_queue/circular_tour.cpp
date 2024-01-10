#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:

    int tour(petrolPump p[],int n)
    {
      
       int lack=0;
       int safe=0;
       int start=0;
       
       for(int i=0;i<n;i++){
           safe=safe+(p[i].petrol-p[i].distance);
           if(safe<0){
               lack=lack+safe;
               safe=0;
               start=i+1;
               
           }
       }
       
       if((lack+safe)>=0){
           return start;
       }
       else{
           return -1;
       }
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
