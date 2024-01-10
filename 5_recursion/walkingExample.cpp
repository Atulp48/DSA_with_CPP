#include<iostream> 
using namespace std;
void reachHome(int src, int dest) {
    cout << "source " << src  << " destination " << dest << endl;
    if(src == dest) {
        cout << " pahuch gya " << endl;
        return ;
    }
    src++;
    reachHome(src, dest);

}
int main() {
    int dest = 10;
    int src = 1;
    cout << endl;
    reachHome(src, dest);
    return 0;
}