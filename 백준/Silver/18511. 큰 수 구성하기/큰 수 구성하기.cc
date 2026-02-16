#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

ll N, ans;
vector<int> K;

void dfs(ll cur)
{
	if (cur > N)
	{

		return;
	}
	if (cur > ans)
	{
		ans = cur;
	}
	int len = K.size();
	for (int i = 0; i < K.size(); i++)
	{
		ll next = cur * 10 + K[i];
		dfs(next);
	}
}

void solve()
{
	int m;
	cin >> N >> m;
	K.resize(m);
	for (int i = 0; i < m; i++)
		cin >> K[i];
	sort(K.begin(), K.end());
	dfs(0);
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}