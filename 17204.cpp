#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	int arr[150];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int result = -1;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		j = arr[j];
		if (j == k) {
			result = i;
			break;
		}
	}
	cout << result;
}