#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void solve() {
	string s; cin >> s;
	int len = s.size();
	int i = 0;
	string ans;
	while (i < len) {
		int cnt = 0;
		while (s[i] == '.') {
			ans += '.';
			i++;
		}
		while (i+cnt < len && s[i+cnt] != '.' )
			cnt++;
		i += cnt;
		if(cnt %2 == 1) {
			cout << -1;
			return;
		}
		while(4 <= cnt) {
			ans += "AAAA";
			cnt -= 4;
		}
		while (2 <= cnt) {
			ans += "BB";
			cnt -= 2;
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}