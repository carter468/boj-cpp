#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	int n_one = 0, n_zero = 0;
	for (auto n : s) {
		if (n == '1') ++n_one;
		else ++n_zero;
	}
	n_one /= 2;
	n_zero /= 2;
	for (auto n : s) {
		if (n == '1') {
			if (n_one > 0) --n_one;
			else cout << n;
		}
		else {
			if (n_zero > 0) {
				cout << n;
				--n_zero;
			}
		}
	}
}