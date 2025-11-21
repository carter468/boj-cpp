// 이름 짓기
// Gold 4, DP

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K,N;cin>>K>>N;

	bool allowed[26][26] = {false};
	for (int i=0;i<K;++i){
		string s;cin>>s;
		int x = s[0]-'a';
		int y = s[1]-'a';
		allowed[x][y] = true;
	}

	vector<vector<long long>> dp(N, vector<long long>(26, 0));
	for (int i=0;i<26;++i) dp[0][i] = 1;
	
	long long result = 0;
	for (int i=1;i<N;++i){
		for (int j=0;j<26;++j){
			for (int k=0;k<26;++k){
				if (allowed[j][k]){
					dp[i][k] = (dp[i][k]+dp[i-1][j])%MOD;
				}
			}
		}
		for (int j=0;j<26;++j){
			result = (result+dp[i][j])%MOD;
		}
	}
	cout<<result;

	return 0;
}
