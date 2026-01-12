#include <iostream>
#include <vector>
using namespace std; //kmp
vector<int> failFunc(string& s) {
    int m = s.length();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}
void solve() {
    int l; string s;
	cin >> l >> s;
    vector<int> pi = failFunc(s);
    int maxv = pi[l - 1];
    cout << l - maxv;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}