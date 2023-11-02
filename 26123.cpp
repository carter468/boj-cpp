#include <iostream>

using namespace std;

int c[300001];

int main()
{
	for (int i = 0; i < 300001; ++i) c[i] = 0;
	int n, d; cin >> n >> d;
	int top = 0;
	long long result = 0;
	while (n--)
	{
		int h; cin >> h;
		c[h]++;
		if (h > top) top = h;
	}
	while (d--)
	{
		if (top == 0) break;
		result += c[top];
		c[top - 1] += c[top];
		top--;
	}
	cout << result;
}