#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool CMP(pair<int, int>a, pair<int, int>b) {
	return (a.first + a.second < b.first + b.second) ? true : false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int result = 0, n, b, count;
	cin >> n >> b;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), CMP);
	for (int i = 0; i < n; ++i) {
		int k = b;

		if (arr[i].first / 2 + arr[i].second <= k) {
			count = 1;
			k -= (arr[i].first / 2 + arr[i].second);
		}
		else count = 0;

		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (arr[j].first + arr[j].second <= k) {
				count++;
				k -= (arr[j].first + arr[j].second);
			}
			else break;
		}

		if (count > result) result = count;
	}

	cout << result;
}