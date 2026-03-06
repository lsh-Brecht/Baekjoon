#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 10007;

int dp[1001][10];

void solve()
{
    int n;
    cin >> n;
    for (int j = 0; j <= 9; ++j)
    {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][0] % mod;
        for (int j = 1; j <= 9; ++j)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    int ans = 0;
    for (int j = 0; j <= 9; ++j)
    {
        ans = (ans + dp[n][j]) % mod;
    }
    cout << ans;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}