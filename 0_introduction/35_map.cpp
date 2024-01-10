#include <iostream>
#include <map>
using namespace std;

int main()
{
map<string, int> map;
map["one"] = 1;
map["two"] = 2;
map["three"] = 3;

std::map<string, int>::iterator it = map.begin();


while (it != map.end())
{
	std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	++it;
}

return 0;
}
