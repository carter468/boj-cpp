#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, answer;
    cin >> a >> b >> c >> d >> e;

    answer = c + d + e;
    a -= d;
    if (c > b)
    {
        c -= b;
        a -= c * 2;
    }
    else
    {
        b -= c;
        answer += b / 2;
        a -= b / 2;
        if (b % 2 == 1)
        {
            answer++;
            a -= 3;
        }
    }
    if (a > 0) answer += (a - 1) / 5 + 1;

    cout << answer;
}