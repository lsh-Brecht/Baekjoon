#include <iostream>
#include <cstdio>
using namespace std; using ll = long long;
ll dp[1001][1001];
const ll mod = 10007;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, r;
	cin >> n >> r;
	//nCr은 n-1Cr-1(첫번째를 고르고 나머지 중 선택) + n-1Cr(첫번째를 고르지 않았을 때)
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) dp[i][j] = 1; //초기값을 주기 위해
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	cout << dp[n][r] % mod;
	return 0;
}