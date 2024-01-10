#include <bits/stdc++.h>

class Node{
    public:

    int data;
    int x;
    int y;

Node(int data,int row,int col){
    this->data=data;
    x=row;
    y=col;
}

};

class arrange{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
   priority_queue<Node*,vector<Node*>,arrange > flag;

    for(int x=0;x<k;x++){
        Node* temp=new Node(kArrays[x][0],x,0);
        flag.push(temp);
    } 

vector<int>result;

while(flag.size()>0){
    Node* temp=flag.top();
    result.push_back(temp->data);
    flag.pop();

    int x=temp->x;
    int y=temp->y;

    if(y+1<kArrays[x].size()){
        Node* next=new Node(kArrays[x][y+1],x,y+1);
        flag.push(next);
    }
}

return result;

}
