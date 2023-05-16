#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int arr[26] = { 0 };

	string s; cin >> s;
	int len = s.length();

	for (auto i : s)
		arr[i - 'a']++;

	if (len < 26)
		for (int i = 0; i < 26; ++i)
			if (arr[i] == 0) {
				cout << s << char('a' + i);
				return 0;
			}

	while (len-- > 0) {
		for (int i = s[len] - 'a' + 1; i < 26; ++i) {
			if (arr[i] == 0) {
				s[len] = char('a' + i);
				cout << s;
				return 0;
			}
		}
		arr[s[len] - 'a']--;
		s[len] = ' ';
	}
	cout << -1;
}