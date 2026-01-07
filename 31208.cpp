// ЕКИПИРОВКА
// Gold 2, greedy, priority queue

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<array<int, 3>> arr;
    arr.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
        arr.push_back({L, R, i});
    }

    sort(arr.begin(), arr.end(),
         [](const array<int, 3> &a, const array<int, 3> &b)
         {
             return a[0] < b[0];
         });

    vector<int> result(N, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int idx = 0;

    for (int i = 1; i <= N; i++)
    {
        while (idx < N && arr[idx][0] <= i)
        {
            pq.push({arr[idx][1], arr[idx][2]});
            idx++;
        }

        if (pq.empty() || pq.top().first < i)
        {
            cout << "NO\n";
            return 0;
        }

        auto [_, a] = pq.top();
        pq.pop();
        result[a] = i;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        cout << result[i] << ' ';
    }

    return 0;
}
