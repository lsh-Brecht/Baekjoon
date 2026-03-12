#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll r = 31;
const ll M = 1234567891;

void solve()
{
	int L;
	string s;
	cin >> L >> s;
	ll ans = 0;
	ll power = 1;
	for (int i = 0; i < L; ++i)
	{
		int a = s[i] - 'a' + 1;
		ans = (ans + a * power) % M;
		power = (power * r) % M;
	}
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}