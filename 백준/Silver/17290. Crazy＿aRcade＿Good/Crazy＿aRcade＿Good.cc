#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int r, c, R = 0, C = 0, v = 99;
    string s;
    cin >> r >> c;
    for (int i = 0; i < 10; ++i) {
        cin >> s;
        for (int j = 0; j < 10; ++j)
            if (s[j] == 'o') R |= (1 << i), C |= (1 << j);
    }
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (!(R & (1 << i)) && !(C & (1 << j)))
                v = min(v, abs(r - 1 - i) + abs(c - 1 - j));
    cout << v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}