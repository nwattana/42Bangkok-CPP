#include <map>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	map<int, float> m;
	pair<int, float> p;

	p = make_pair(10, 10000);
	m.insert(make_pair(-10, -10000));
	m.insert(make_pair(-100, -99));
	m.insert(make_pair(100, -99));
	m.insert(p);
	if (m.find(-99) == m.end())
		cout << "Not Found" << std::endl;

	// cout << ()->first << std::endl;
	cout << (m.find(-1))->second << std::endl;
}