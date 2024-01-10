#include <iostream>
#include <queue>
using namespace std;

int main()
{
    deque<int> n;

    n.push_front(12);
    n.push_back(13);

    cout << n.front() << endl;
    cout << n.back() << endl;
    n.pop_back();
    cout << n.front() << endl;
    cout << n.back() << endl;
    n.pop_front();

    if (n.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }

    return 0;
}