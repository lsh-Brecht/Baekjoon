#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int t = a % b;
	while (t) {
		a = b; b = t; t = a % b;
	}
	return b;
}
void solve() {
	int n, m; cin >> n >> m;
	cout << m - gcd(n, m);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}