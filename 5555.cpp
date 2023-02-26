#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	getline(cin, str1);
	int n, count = 0; cin >> n; cin.ignore();
	while (n--) {
		getline(cin, str2);
		if ((str2 + str2).find(str1) != string::npos) count++;
	}

	cout << count;
}