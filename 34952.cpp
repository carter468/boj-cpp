// 동전 뒤집기 게임과 쿼리
// Platinum 4, segtree, game theory

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int left, right;
    int h, t;
};

int N;
vector<int> S;
vector<Node> tree;

Node mergeNode(const Node &L, const Node &R)
{
    if (L.left == -1)
        return R;
    if (R.left == -1)
        return L;

    Node res;
    res.left = L.left;
    res.right = R.right;
    res.h = L.h + R.h;
    res.t = L.t + R.t;

    if (L.right == R.left)
    {
        if (L.right == 0)
            res.h--;
        else
            res.t--;
    }
    return res;
}

Node init(int start, int end, int node)
{
    if (start == end)
    {
        if (S[start] == 0)
            return tree[node] = {0, 0, 1, 0};
        else
            return tree[node] = {1, 1, 0, 1};
    }

    int mid = (start + end) / 2;
    Node L = init(start, mid, node * 2);
    Node R = init(mid + 1, end, node * 2 + 1);
    return tree[node] = mergeNode(L, R);
}

Node query(int start, int end, int node, int left, int right)
{
    if (right < start || end < left)
        return {-1, -1, 0, 0};

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    Node L = query(start, mid, node * 2, left, right);
    Node R = query(mid + 1, end, node * 2 + 1, left, right);
    return mergeNode(L, R);
}

Node update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
    {
        if (S[start] == 0)
            return tree[node] = {0, 0, 1, 0};
        else
            return tree[node] = {1, 1, 0, 1};
    }

    int mid = (start + end) / 2;
    Node L = update(start, mid, node * 2, idx);
    Node R = update(mid + 1, end, node * 2 + 1, idx);
    return tree[node] = mergeNode(L, R);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    S.resize(N);

    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        S[i] = (c == 'H' ? 0 : 1);
    }

    tree.resize(4 * N);
    init(0, N - 1, 1);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int i;
            cin >> i;
            --i;
            S[i] ^= 1;
            update(0, N - 1, 1, i);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            Node res = query(0, N - 1, 1, l - 1, r - 1);
            if (res.h > res.t)
                cout << "First\n";
            else if (res.h < res.t)
                cout << "Second\n";
            else if (res.h % 2 == 1)
                cout << "Second\n";
            else
                cout << "First\n";
        }
    }
    return 0;
}
