#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;
	int arr[41] = { 0 };
	for (int i = 0; i < m; ++i) {
		int a; cin >> a;
		arr[a] = 1;
	}

	int dp[41][2] = { 0 };
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (arr[i] == 0) {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
		else {
			dp[i][0] = dp[i - 1][0];
		}
	}

	cout << dp[n][0];
}