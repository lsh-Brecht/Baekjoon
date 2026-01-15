#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	string s = "";
	for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		s.push_back(c);
	}
	int left = 0, right = n-1;
	string ans = "";
	while (left <= right) {
		if(s[left] < s[right])
			ans.push_back(s[left++]);
		else if(s[left] > s[right])
			ans.push_back(s[right--]);
		else {
			int l = left, r = right;
			bool isLeft = false;
			while (l <= r) {
				if (s[l] < s[r]) {
					isLeft = true;
					break;
				}
				else if (s[l] > s[r]) {
					isLeft = false;
					break;
				}
				l++; r--;
			}
			if (isLeft)
				ans.push_back(s[left++]);
			else
				ans.push_back(s[right--]);
		}
	}
	int len = ans.size();
	for (int i = 0; i < len; ++i) {
		cout << ans[i];
		if ((i + 1) % 80 == 0) cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}