#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	int x = -1, y = -1, l = 0;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (x == -1 and y == -1 and grid[i][j] == '#') {
				x = i; y = j;
			}
		}

	for (int i = y; i < m; i++) {
		if (grid[x][i] == '.') break;
		l++;
	}

	if (y + l + 1 <= m and grid[x][y + l + 1] == '#') cout << "UP";
	else if (grid[x + l - 1][y + l / 2] == '.') cout << "DOWN";
	else if (grid[x + l / 2][y] == '.') cout << "LEFT";
	else cout << "RIGHT";
}