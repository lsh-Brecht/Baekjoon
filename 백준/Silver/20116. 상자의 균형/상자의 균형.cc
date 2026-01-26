#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> boxes;
void solve() {
	int n, s; cin >> n >> s;
	boxes.resize(n);
	for (int i = 0; i < n; ++i) {
		cin>> boxes[i];
	}
	ll sum = 0;
	for (int i = n - 1; i > 0; --i) {
		sum += boxes[i];
		if (sum <=(boxes[i-1]-s)*(n - i) || (boxes[i-1]+s)*(n - i) <= sum) {
			cout << "unstable";
			return;
		}
	}
	cout << "stable";
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}