#include <iostream>
using namespace std;
using ll = long long;

void solve() {
	int n, x, y; cin >> n >> x >> y;
	int diag = x * x + y * y;
	for (int i = 0; i < n; ++i)
	{
		int d; cin >> d;
		if (d * d > diag)
			cout << "NE" << '\n';
		else
			cout << "DA" << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}