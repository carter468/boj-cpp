// Set Theory
// Platinum 5, constructive, bruteforcing

// 다른 풀이 : A원소들의 dif를 다 구하고 모든 dif의 약수가 되지 않는 수를 찾아서 등차수열을 만든다.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int LIMIT = 1000000;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &x : A)
            cin >> x;

        vector<char> banned(LIMIT + 1, 0);
        vector<int> B;
        int cur = 1;

        while (B.size() < N)
        {
            while (banned[cur])
                ++cur;
            B.push_back(cur);

            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                {
                    int x = A[i] - A[j] + cur;
                    if (1 <= x && x <= LIMIT)
                        banned[x] = 1;
                }
            ++cur;
        }

        cout << "YES\n";
        for (auto b : B)
            cout << b << ' ';
        cout << '\n';
    }
}
