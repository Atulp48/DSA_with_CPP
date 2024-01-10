#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


#include<vector>
class Solution{
    private:
    bool check(vector<int>A){
        int x=0;
        int y=A.size()-1;
        while(x<y){
            if(A[x]!=A[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    
  public:
    bool isPalindrome(Node *head)
    {
        
        vector<int>A;
        Node * flag=head;
        while(flag!=NULL){
            A.push_back(flag->data);
            flag=flag->next;
        }
        return check(A);
    }
};


int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;

        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
