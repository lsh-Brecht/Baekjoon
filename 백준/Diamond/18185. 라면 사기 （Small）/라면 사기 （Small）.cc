#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int fac[10003];
void solve() {
	int n; cin >> n;
	ll cost = 0, k;
    //단순히 많이 묶으면 fragmentation으로 불필요한 비용 발생
    for (int i = 0; i < n; ++i) cin >> fac[i];
    for (int i = 0; i < n; ++i) {
        if (fac[i + 1] > fac[i + 2]) {
            k = min(fac[i], fac[i + 1] - fac[i + 2]);
            cost += 5 * k; fac[i] -= k; fac[i + 1] -= k;
        }
        k = min({ fac[i], fac[i + 1], fac[i + 2] });
        cost += 7 * k; fac[i] -= k; fac[i + 1] -= k; fac[i + 2] -= k;
        k = min(fac[i], fac[i + 1]);
        cost += 5 * k; fac[i] -= k; fac[i + 1] -= k;
        cost += 3 * fac[i];
    }
    cout << cost;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}