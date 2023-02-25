#include <iostream>

using namespace std;

int main() {
	int a, b, c = 0, d = 0, e, f, g = 0;
	// 준현현금,성민현금,준현개수,성민개수,전날주가,오늘주가,주식흐름
	cin >> a;
	b = a;

	cin >> e;
	c = a / e;
	a -= e * c;
	for (int i = 0; i < 13; i++) {
		cin >> f;
		//준현
		c += a / f;
		a -= a / f * f;

		//성민
		if (e == f) g = 0;	// 고정
		else if (f < e) {	// 하락
			if (g < 0) g--;
			else g = -1;
		}
		else { // 상승
			if (g > 0) g++;
			else g = 1;
		}

		if (g > 2) { // 매도타이밍
			b += f * d;
			d = 0;
		}
		else if (g < -2) { // 매수타이밍
			d += b / f;
			b -= b / f * f;
		}
		e = f;
	}
	// 정산
	a += f * c;
	b += f * d;
	if (a > b) cout << "BNP";
	else if (a < b) cout << "TIMING";
	else cout << "SAMESAME";
}