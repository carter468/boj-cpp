#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

	int n; cin >> n;
	int height[100][100];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> height[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < 101; ++i) {
		int visit[100][100] = { 0 };
		int count = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (visit[j][k] == 0 && height[j][k] > i) {
					++count;
					queue<pair<int, int>> q;
					q.push(pair<int, int>(j, k));
					visit[j][k] = 1;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						for (int l = 0; l < 4; ++l) {
							int nx = x + dx[l], ny = y + dy[l];
							if (nx < 0 || nx == n || ny < 0 || ny == n || visit[nx][ny] == 1 || height[nx][ny] <= i) continue;
							visit[nx][ny] = 1;
							q.push(pair<int, int>(nx, ny));
						}
					}
				}
			}
		}
		if (count > result) result = count;
	}
	cout << result;
}