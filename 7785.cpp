#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<string, int, greater<string>> employee;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, record;
		cin >> name >> record;
		if (record == "enter") employee[name] = 1;
		else employee.erase(name);
	}
	for (auto i = employee.begin(); i != employee.end(); i++) std::cout << i->first << "\n";
}