#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

long long Hash(int a, int b, int c, int d) {
	return a * 601 * 601 * 601 + b * 601 * 601 + c * 601 + d;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		string w; cin >> w;
		map<long long, int> cs;
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i < k; ++i) {
			if (w[i] == 'A') a++;
			if (w[i] == 'G') b++;
			if (w[i] == 'C') c++;
			if (w[i] == 'T') d++;
		}
		cs[Hash(a, b, c, d)] = 1;
		for (int i = k; i < w.length(); ++i) {
			if (w[i] == 'A') a++;
			if (w[i] == 'G') b++;
			if (w[i] == 'C') c++;
			if (w[i] == 'T') d++;
			if (w[i - k] == 'A') a--;
			if (w[i - k] == 'G') b--;
			if (w[i - k] == 'C') c--;
			if (w[i - k] == 'T') d--;
			long long x = Hash(a, b, c, d);
			if (cs.find(x) == cs.end()) cs[x] = 1;
			else cs[x]++;
		}
		int result = 0;
		for (const auto& pair : cs) {
			if (result < pair.second) result = pair.second;
		}
		cout << result << "\n";
	}
}