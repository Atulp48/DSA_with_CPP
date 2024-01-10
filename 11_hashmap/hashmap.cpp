#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

int main()
{

    unordered_map<string, int> flag;

    pair<string, int> temp = make_pair("hi", 2);
    flag.insert(temp);

    // or
    pair<string, int> greet("hello", 3);
    flag.insert(greet);

    // or 

    flag["how"] = 6;

    for (auto i : flag)
    {
        cout << i.first << ": " << i.second << endl;
        cout << endl;
    }

    cout << flag["hi"] << endl;
    cout << flag.at("hi") << endl;

    cout << flag["NA"] << endl;
    cout << flag.at("NA") << endl;

    cout << flag.size() << endl;
    cout << flag.count("NA") << endl;

    flag.erase("NA");
    cout << flag.size() << endl;
    return 0;
}