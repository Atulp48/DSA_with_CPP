#include<iostream>
using namespace std;

int main() {

    int n = 10;

    int a = 0;
    int b = 1;
    cout<<a <<" " <<b<<" ";
    for(int i = 1; i<=n; i++ ) {
        
        int temp = a+b;
        cout<<temp<<" ";

        a = b;
        b = temp;
    }
    return 0;
}