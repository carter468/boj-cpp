#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c, d; cin >> a >> b >> c >> d;

	bool seive[1001] = { false };
	for (int i = 2; i <= sqrt(1001); ++i)
		if (seive[i] == false)
			for (int j = i * i; j < 1001; j += i)
				seive[j] = true;

	int x = 0, y = 0, z = 0;
	for (int i = 2; i < 1001; ++i) {
		if (seive[i]) continue;
		if (a <= i && i <= b && c <= i && i <= d) ++z;
		else if (a <= i && i <= b) ++x;
		else if (c <= i && i <= d) ++y;
	}
	(x + z % 2 > y) ? cout << "yt" : cout << "yj";
}