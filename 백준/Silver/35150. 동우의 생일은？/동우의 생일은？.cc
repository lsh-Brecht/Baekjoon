#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void solve() {
    ll a,b, c;
    cin >> a >> b >> c;
    //홀수인 경우 때문
    ll k1 = c/ 2;
    ll k2 = c - k1;
    ll W = k1 * a + k2 * b;
    ll H = k1 * b + k2 * a;
    cout << W * H << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
	    solve();
    }
	return 0;
}