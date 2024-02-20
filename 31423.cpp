#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string arr[500001];
bool visited[5000001];
vector<int> graph[500001];

void solve(int x) {
	cout << arr[x];
	for (int i = 0; i < graph[x].size(); ++i) {
		int nx = graph[x][i];
		if (visited[nx] == false) {
			visited[nx] = true;
			solve(nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	int p = 0;
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		visited[i] = false;
		p = a;
	}
	solve(p);
}

