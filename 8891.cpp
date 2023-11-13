#include <iostream>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int x = 0, y = 0;
		for (int i = 0; i < 2; i++)
		{
			int a; cin >> a;
			int j = 0, k = 0;
			while (k < a) k += ++j;
			x += j - (k - a);
			y += 1 + (k - a);
		}
		int c = x + y;
		cout << c * (c - 1) / 2 - (y - 1) << "\n";
	}
}