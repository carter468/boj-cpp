// Pretty Pens
// Platinum 4, greedy, set

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, Q;
vector<int> C;
vector<ll> P;
vector<multiset<ll>> color;

set<pair<ll, int>> best;
multiset<pair<ll, int>> others;
ll result = 0;

void remove_value(int c, ll p)
{
    bool was_best = (!color[c].empty() && *color[c].rbegin() == p);

    color[c].erase(color[c].find(p));

    if (was_best)
    {
        best.erase({p, c});
        result -= p;

        if (!color[c].empty())
        {
            ll nm = *color[c].rbegin();
            best.insert({nm, c});
            result += nm;

            auto it = others.find({nm, c});
            if (it != others.end())
                others.erase(it);
        }
    }
    else
    {
        auto it = others.find({p, c});
        if (it != others.end())
            others.erase(it);
    }
}

void add_value(int c, ll p)
{
    if (color[c].empty())
    {
        color[c].insert(p);
        best.insert({p, c});
        result += p;
        return;
    }

    ll cur = *color[c].rbegin();
    if (p > cur)
    {
        best.erase({cur, c});
        result -= cur;
        others.insert({cur, c});

        best.insert({p, c});
        result += p;
    }
    else
    {
        others.insert({p, c});
    }
    color[c].insert(p);
}

void print_answer()
{
    ll ans = result;
    if (!others.empty() && !best.empty())
    {
        ll a = others.rbegin()->first;
        ll b = best.begin()->first;
        if (a > b)
            ans += a - b;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    C.assign(N + 1, 0);
    P.assign(N + 1, 0);
    color.assign(M + 1, {});

    for (int i = 1; i <= N; i++)
    {
        cin >> C[i] >> P[i];
        color[C[i]].insert(P[i]);
    }

    for (int i = 1; i <= M; i++)
    {
        auto it = prev(color[i].end());
        ll mx = *it;
        best.insert({mx, i});
        result += mx;

        for (auto jt = color[i].begin(); jt != it; ++jt)
            others.insert({*jt, i});
    }

    print_answer();

    while (Q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int i, nc;
            cin >> i >> nc;
            int oc = C[i];
            if (oc != nc)
            {
                remove_value(oc, P[i]);
                add_value(nc, P[i]);
                C[i] = nc;
            }
        }
        else
        {
            int i;
            ll np;
            cin >> i >> np;
            if (P[i] != np)
            {
                remove_value(C[i], P[i]);
                add_value(C[i], np);
                P[i] = np;
            }
        }
        print_answer();
    }
}
