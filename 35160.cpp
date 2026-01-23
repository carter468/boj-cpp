// 명사수
// Platinum 5, lazy propagation

#include <bits/stdc++.h>
using namespace std;

const long long NEG_INF = -(1LL << 60);

int N, Q, C;
vector<int> arr;
vector<int> seg, lazy;

long long init(int x, int s, int e)
{
    if (s == e)
    {
        return seg[x] = arr[s];
    }
    int m = (s + e) >> 1;
    return seg[x] = max(init(x << 1, s, m), init(x << 1 | 1, m + 1, e));
}

inline void propagation(int x, int s, int e)
{
    if (lazy[x] != 0)
    {
        seg[x] += lazy[x];
        if (s != e)
        {
            lazy[x << 1] += lazy[x];
            lazy[x << 1 | 1] += lazy[x];
        }
        lazy[x] = 0;
    }
}

void update(int x, int l, int r, int s, int e, long long dif)
{
    propagation(x, l, r);

    if (r < s || e < l)
        return;

    if (s <= l && r <= e)
    {
        seg[x] += dif;
        if (l != r)
        {
            lazy[x << 1] += dif;
            lazy[x << 1 | 1] += dif;
        }
        return;
    }

    int m = (l + r) >> 1;
    update(x << 1, l, m, s, e, dif);
    update(x << 1 | 1, m + 1, r, s, e, dif);
    seg[x] = max(seg[x << 1], seg[x << 1 | 1]);
}

long long query(int x, int l, int r, int s, int e)
{
    propagation(x, l, r);

    if (r < s || e < l)
        return NEG_INF;
    if (s <= l && r <= e)
        return seg[x];

    int m = (l + r) >> 1;
    return max(query(x << 1, l, m, s, e), query(x << 1 | 1, m + 1, r, s, e));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q >> C;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i] += max(C - i - 1, 0);
    }

    seg.assign(4 * N, 0);
    lazy.assign(4 * N, 0);
    init(1, 0, N - 1);

    long long result = 0;
    int i = 0;

    while (Q--)
    {
        long long x = query(1, 0, N - 1, 0, N - 1);
        result += x;

        int j = i + min(C - 1, N);

        if (j >= N)
        {
            update(1, 0, N - 1, i + 1, N - 1, 1);
            update(1, 0, N - 1, 0, j - N, 1);
        }
        else
        {
            update(1, 0, N - 1, i + 1, j, 1);
        }

        update(1, 0, N - 1, i, i, max(C - N - 1, 0) - C + 1);
        i = (i + 1) % N;
    }

    cout << result << '\n';
    return 0;
}
