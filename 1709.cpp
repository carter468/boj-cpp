// 타일 위의 원
// Gold 4, bruteforcing, geometry

#include <bits/stdc++.h>
using namespace std;

long long isqrt(long long x)
{
    long long r = sqrt((long double)x);
    while ((r + 1) * (r + 1) <= x)
        ++r;
    while (r * r > x)
        --r;
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R;
    cin >> R;
    R /= 2;

    long long rr = R * R;
    long long m = isqrt(rr / 2);

    long long c = R * 8 - 4;

    for (long long a = 1; a <= m; ++a)
    {
        long long b = rr - a * a;
        long long s = isqrt(b);
        if (s * s == b)
        {
            c -= 8;
        }
    }

    cout << c << '\n';
    return 0;
}
