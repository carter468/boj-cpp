#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int M = 1e9 + 7;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dp[201][403][403];

int main() {
    int xs, ys, t; cin >> xs >> ys >> t;

    int xh, yh; cin >> xh >> yh;
    xh -= xs;
    yh -= ys;

    int n; cin >> n;

    set<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arr.emplace(x - xs, y - ys);
    }

    if (abs(xh) + abs(yh) > t) {
        cout << 0 << endl;
        return 0;
    }

    dp[0][t][t] = 1;

    for (int i = 1; i <= t; ++i) {
        for (int j = -i; j <= i; ++j) {
            for (int k = -i + abs(j); k <= i - abs(j); ++k) {
                if (arr.count({ j, k })) continue;
                for (int d = 0; d < 4; ++d) {
                    int x = j + dx[d];
                    int y = k + dy[d];
                    if (x != xh || y != yh) {
                        dp[i][j + t][k + t] = (dp[i][j + t][k + t] + dp[i - 1][x + t][y + t]) % M;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= t; ++i) {
        result = (result + dp[i][xh + t][yh + t]) % M;
    }

    cout << result << endl;
    return 0;
}
