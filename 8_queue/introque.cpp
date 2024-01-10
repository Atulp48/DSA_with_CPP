#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>s;
    s.push(5);
    s.push(6);
    cout<<"the size of queue is "<<s.size()<<endl;
    if(s.empty()){
        cout<<"the queue is empty"<<endl;
    }
    else{
        cout<<"the  queue is not empty"<<endl;
    }

    cout<<"the top of the queue is "<<s.front()<<endl;
}