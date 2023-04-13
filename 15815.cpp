#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	int len = s.length();

	stack<int> stack;
	for (int i = 0; i < len; ++i) {
		if (isdigit(s[i]) == 0) {
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			if (s[i] == '*') stack.push(a * b);
			else if (s[i] == '/') stack.push(a / b);
			else if (s[i] == '+') stack.push(a + b);
			else if (s[i] == '-') stack.push(a - b);
		}
		else stack.push(s[i] - 48);
	}

	cout << stack.top();
}