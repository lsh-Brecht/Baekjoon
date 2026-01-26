#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> boxes;
vector<ll> accSum;
void solve() {
	int n, s; cin >> n >> s;
	boxes.resize(n);  accSum.resize(n);
	for (int i = 0; i < n; ++i) {
		cin>> boxes[i];
	}
	accSum[n - 1] = boxes[n - 1];
	for (int i = n-2; i >= 0; --i) {
		accSum[i] = boxes[i] + accSum[i + 1];
	}
	bool f = true;
	for (int i = n - 1; i > 0; --i) {
		if (accSum[i] <=(boxes[i-1]-s)*(n - i) || (boxes[i-1]+s)*(n - i) <= accSum[i]) {
			f = false;
			break;
		}
	}
	cout << (f ? "stable" : "unstable");
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}