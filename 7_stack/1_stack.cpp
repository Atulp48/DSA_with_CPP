#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    s.pop();
    cout << "the value at the top of the stack is " << s.top() << endl;
    cout << "the size of the stack is " << s.size() << endl;
    return 0;
}
