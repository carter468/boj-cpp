#include <iostream>

using namespace std;

int main() {
	int a, b, c = 0, d = 0, e, f, g = 0;
	// ��������,��������,��������,���ΰ���,�����ְ�,�����ְ�,�ֽ��帧
	cin >> a;
	b = a;

	cin >> e;
	c = a / e;
	a -= e * c;
	for (int i = 0; i < 13; i++) {
		cin >> f;
		//����
		c += a / f;
		a -= a / f * f;

		//����
		if (e == f) g = 0;	// ����
		else if (f < e) {	// �϶�
			if (g < 0) g--;
			else g = -1;
		}
		else { // ���
			if (g > 0) g++;
			else g = 1;
		}

		if (g > 2) { // �ŵ�Ÿ�̹�
			b += f * d;
			d = 0;
		}
		else if (g < -2) { // �ż�Ÿ�̹�
			d += b / f;
			b -= b / f * f;
		}
		e = f;
	}
	// ����
	a += f * c;
	b += f * d;
	if (a > b) cout << "BNP";
	else if (a < b) cout << "TIMING";
	else cout << "SAMESAME";
}