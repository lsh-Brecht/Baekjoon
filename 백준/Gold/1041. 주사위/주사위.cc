#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll arr[6];
void solve() {
	ll n, sumv = 0, maxv = -1; cin >> n;
	for (int i = 0; i < 6; ++i) {
		cin >> arr[i];
		sumv += arr[i];
		maxv = max(maxv, arr[i]);
	};
	//단순 정렬이 아니라 배치를 고려해야 함
	ll m1 = min(arr[0], arr[5]);
	ll m2 = min(arr[1], arr[4]);
	ll m3 = min(arr[2], arr[3]);

	ll min_a = m1 + m2 + m3;
	ll min_b = min({ m1, m2, m3 });
	ll min_c = min({ m1 + m2, m2 + m3, m3 + m1 });

	ll b = 4LL * (n - 1) * (n - 2) + (n - 2) * (n - 2);
	ll c = 4LL * (n - 1) + 4LL * (n - 2);
	if(n==1)
		cout << sumv - maxv;
	else
		cout << 4LL * min_a + b * min_b + c * min_c;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}