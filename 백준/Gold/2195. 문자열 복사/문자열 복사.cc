#include <iostream>
#include <string>
using namespace std;
using ll = long long;
//fail function 비슷한 문제인듯

void solve() {
    string s, p; cin >> s >> p;
    int pos = 0, ans = 0;
	int pLen = p.length();
	int sLen = s.length();
    while (pos < pLen) {
        int maxv = 0;
        for (int i = 0; i < sLen; i++) {
            int k = 0;
            while (pos + k < pLen && i + k < sLen && p[pos + k] == s[i + k]) k++;
            maxv = max(maxv, k);
        }
        pos += maxv;
        ans++;
    }
    cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}