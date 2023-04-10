#include <iostream>

using namespace std;

typedef struct {
	int a, b, c, result;
} testset;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, b, c, n; cin >> a >> b >> c >> n;;
	int result[301];
	for (int i = 1; i <= a + b + c; ++i) result[i] = 2;
	testset test[1000];
	for (int i = 0; i < n; ++i)
		cin >> test[i].a >> test[i].b >> test[i].c >> test[i].result;


	for (int i = 0; i < n; ++i)
		if (test[i].result == 1) {
			result[test[i].a] = 1; result[test[i].b] = 1; result[test[i].c] = 1;
		}
	for (int i = 0; i < n; ++i) {
		if (test[i].result == 0) {
			int temp = 0;
			if (result[test[i].a] == 1) ++temp;
			if (result[test[i].b] == 1) ++temp;
			if (result[test[i].c] == 1) ++temp;
			if (temp == 2) {
				if (result[test[i].a] == 2) result[test[i].a] = 0;
				else if (result[test[i].b] == 2) result[test[i].b] = 0;
				else if (result[test[i].c] == 2) result[test[i].c] = 0;
			}
		}
	}

	for (int i = 1; i <= a + b + c; ++i) cout << result[i] << '\n';
}