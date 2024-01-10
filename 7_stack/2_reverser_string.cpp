#include <iostream>
#include <stack>
using namespace std;

stack<char> stc;
int main()
{
    string str1 = "";
    string str = "kingo";
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        stc.push(c);
    }

    while (!stc.empty())
    {

        char c1 = stc.top();
        str1.push_back(c1);
        stc.pop();
    }
    cout << str1 << endl;
    return 0;
}