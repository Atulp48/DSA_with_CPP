#include<iostream>
using namespace std;

void fun(int n ) {
    n++;
    cout << " n is " << n <<endl;

}
int main() {
    int n;
    cin >> n;
    fun(n);
    cout<<"number n is "<< n << endl;


    return 0;
}