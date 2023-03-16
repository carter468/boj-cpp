#include <iostream>

using namespace std;

int main()
{
	int n, m; cin >> n >> m;;
	int num[101];
	for (int i = 1; i < 101; ++i) num[i] = 1;
	for (int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y;
		for (int j = x; j < y; ++j)
		{
			n -= num[j];
			num[j] = 0;
		}
	}
	cout << n;
}