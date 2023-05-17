#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	int a = 1;
	long long b = 10, result = 0;
	while (b <= n) {
		result += a * b * 0.9;
		a++;
		b *= 10;
	}
	result += (n - b / 10 + 1) * a;
	cout << result % 1234567;
}