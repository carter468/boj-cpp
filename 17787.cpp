#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    vector<int> result;

    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> m(n);
        m[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            m[i] = max(m[i + 1], arr[i]);
        }

        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (m[i] == arr[i]) continue;

            int a = m[i];
            int b = arr[i];

            auto it = s.lower_bound(a);
            if (it != s.begin()) {
                auto prev_it = prev(it);
                if (*prev_it > b) {
                    result.push_back(t);
                    break;
                }
            }
            s.insert(b);
        }
    }

    cout << result.size() << "\n";
    for (int r : result) {
        cout << r << "\n";
    }

    return 0;
}
