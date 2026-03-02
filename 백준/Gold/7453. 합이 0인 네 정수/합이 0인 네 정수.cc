#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

int n, A[4000], B[4000], C[4000], D[4000], S[16000000];
int k;
ll ans;
int count_val(int t)
{
	auto low = lower_bound(S, S + k, t);
	auto up = upper_bound(S, S + k, t);
	return up - low;
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			S[k++] = A[i] + B[j];
		}
	}
	sort(S, S + k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans += count_val(-C[i] - D[j]);
		}
	}
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}