#include<iostream>
#include<string>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	string a, b, c="", d = "";
	cin >> a >> b;

	int e = a.length(), f = b.length();
	int lcm = e * f / gcd(e, f);
	for (int i = 0; i < lcm / e; i++) c += a;
	for (int i = 0; i < lcm / f; i++) d += b;

	cout << (c==d ? 1 : 0);
}
