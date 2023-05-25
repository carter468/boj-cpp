#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	string arr[30];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 2; ++j) {
			if (arr[i][j] != '.' && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) {
				cout << arr[i][j];
				return 0;
			}
			if (arr[j][i] != '.' && arr[j][i] == arr[j + 1][i] && arr[j][i] == arr[j + 2][i]) {
				cout << arr[j][i];
				return 0;
			}
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < n - 2; ++j) {
			if (arr[i][j] != '.' && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2]) {
				cout << arr[i][j];
				return 0;
			}
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 2; j < n; ++j) {
			if (arr[i][j] != '.' && arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2]) {
				cout << arr[i][j];
				return 0;
			}
		}
	}
	cout << "ongoing";
}