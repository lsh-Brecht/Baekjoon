#include <iostream>
#include <string>
using namespace std; //프언 regular expression으로도 가능

bool patternMat(string& s, int len) {
    int idx = 0;
    if (idx < len && s[idx] >= 'A' && s[idx] <= 'F') {
        if (s[idx] != 'A') ++idx;
    }
    else
		return false;

    int cnt = 0;
    while (idx < len && s[idx] == 'A') {
        idx++;
        cnt++;
    }
    if (cnt == 0) return false;
    cnt = 0;
    while (idx < len && s[idx] == 'F') {
        idx++;
        cnt++;
    }
    if (cnt == 0) return false;
    cnt = 0;
    while (idx < len && s[idx] == 'C') {
        idx++;
        cnt++;
    }
    if (cnt == 0) return false;

    if (idx < len && s[idx] >= 'A' && s[idx] <= 'F')
        idx++;

    return idx == len;
}
void solve() {
	string s; cin >> s;
	int sLen = s.size();
    bool ans = patternMat(s, sLen);
    if(ans)
        cout << "Infected!" <<'\n';
    else
		cout << "Good" << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) { solve(); }
	return 0;
}