#include<iostream>

using namespace std;

int main()
{
	long long i = 1, s; cin >> s;

	while (i * (i + 1) / 2 <= s) i++;

	cout << i - 1;
}