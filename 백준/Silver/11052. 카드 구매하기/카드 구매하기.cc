#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
using ll = long long;

vector<int> P;
vector<int> dp;
void solve()
{
    int N;
    cin >> N;
	P.resize(N + 1);
	dp.resize(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> P[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int k = 1; k <= i; ++k)
        {
            dp[i] = max(dp[i], dp[i - k] + P[k]);
        }
    }
    cout << dp[N];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}