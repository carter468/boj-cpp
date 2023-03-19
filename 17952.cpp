#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, result = 0, i, a, t; cin >> n;
	stack<pair<int, int>> st;
	pair<int, int> hw;
	while (n--) {
		cin >> i;
		if (i == 1) {
			cin >> a >> t;
			st.push(make_pair(a, t));
		}
		if (st.empty()) continue;
		hw = st.top();
		st.pop();
		if (hw.second == 1) result += hw.first;
		else st.push(make_pair(hw.first, hw.second - 1));
	}
	cout << result;
}