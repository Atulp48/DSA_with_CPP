#include <map>
#include <iostream>
using namespace std;

int main()
{

    map<string, int> flag;

    pair<string, int> temp = make_pair("hi", 3);
    flag.insert(temp);

    // or
    pair<string, int> greet("hello", 2);
    flag.insert(greet);

    // or

    flag["how"] = 1;

    map<string, int>::iterator flag1 = flag.begin();

    while (flag1 != flag.end())
    {
        cout << flag1->first << " " << flag1->second << endl;
        flag1++;
    }

    return 0;
}