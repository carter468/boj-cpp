#include <iostream>

using namespace std;

static int result = 0;
int a, b;

void bt(int n) {
	if (a <= n && n <= b) ++result;
	if (n > b || n > 100000000) return;
	bt(n * 10 + 4); bt(n * 10 + 7);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> a >> b;
	bt(4); bt(7);
	cout << result;
}