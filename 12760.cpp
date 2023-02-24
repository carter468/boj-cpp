#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m, max_val;

	cin >> n >> m;
	vector<vector<int>> num(n, vector<int>(m));
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> num[i][j];
		sort(num[i].begin(), num[i].end(), cmp);
	}
	for (int i = 0; i < m; i++) {
		max_val = 0;
		for (int j = 0; j < n; j++)
			max_val = max(max_val, num[j][i]);
		for (int j = 0; j < n; j++)
			if (max_val == num[j][i]) ans[j]++;
	}
	max_val = 0;
	for (int i = 0; i < n; i++)
		max_val = max(max_val, ans[i]);
	for (int i = 0; i < n; i++)
		if (ans[i] == max_val) cout << i + 1 << ' ';
}