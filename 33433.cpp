// Snake Move
// Platinum 5, dijkstra

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> snake(K);
    for (int i = 0; i < K; i++)
        cin >> snake[i].first >> snake[i].second;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    int sx = snake[0].first;
    int sy = snake[0].second;

    vector<vector<ll>> wait(N, vector<ll>(M, 0));

    for (int i = 0; i < K; i++)
    {
        auto [x, y] = snake.back();
        snake.pop_back();
        wait[x - 1][y - 1] = i + 1;
    }

    vector<vector<ll>> dist(N, vector<ll>(M, INF));
    dist[sx - 1][sy - 1] = 0;

    priority_queue<
        tuple<ll, int, int>,
        vector<tuple<ll, int, int>>,
        greater<>>
        pq;

    pq.emplace(0, sx - 1, sy - 1);

    unsigned long long result = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!pq.empty())
    {
        auto [d, x, y] = pq.top();
        pq.pop();

        if (d > dist[x][y])
            continue;

        result += d * d;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (grid[nx][ny] == '#')
                continue;

            ll nd = max(d + 1, wait[nx][ny]);

            if (nd < dist[nx][ny])
            {
                dist[nx][ny] = nd;
                pq.emplace(nd, nx, ny);
            }
        }
    }

    cout << result << "\n";
}
