#include<iostream>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--) {
		int n, l, f, count = 0, c[500] = { 0 };
		string word[500];

		cin >> n >> l >> f;
		for (int i = 0; i < n; i++) cin >> word[i];

		for (int i = 0; i < n; i++)
			if (c[i] == 0)
				for (int j = i + 1; j < n; j++)
					if (word[i].substr(l - f) == word[j].substr(l - f)) {
						count++;
						c[i] = 1; c[j] = 1;
						break;
					}

		cout << count << '\n';
	}
}