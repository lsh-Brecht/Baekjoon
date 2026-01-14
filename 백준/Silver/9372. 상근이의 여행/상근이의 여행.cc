#include <iostream>
using namespace std;

void solve() {
	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n>>m;
		for (int i = 0; i < m; ++i) {
			int u, v; cin >> u >> v;
		}
		cout << (n - 1) <<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}