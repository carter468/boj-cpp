#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n; cin >> n;
	set<string> group;
	for (int i = 0; i < n; i++)
	{
		string a; cin >> a;
		sort(a.begin(), a.end());
		if (group.find(a) == group.end()) group.insert(a);
	}
	cout << group.size();
}