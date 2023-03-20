#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	unordered_map<string, int> order;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string name; cin >> name;
		order[name] = i;
	}

	int submit[2500];
	for (int i = 0; i < n; ++i) {
		string j; cin >> j;
		submit[i] = order[j];
	}

	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (submit[i] < submit[j]) count++;

	cout << count << "/" << n * (n - 1) / 2;
}