#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

void solve() {
    string input; cin >> input;
    if (input == "P") {
        cout << "PPAP";
        return;
    }
    string s = "";
    for (int i = 0; i < input.length(); i++) {
        s.push_back(input[i]);

        if (s.length() >= 4) {
            int n = s.length();
            if (s[n - 4] == 'P' &&
                s[n - 3] == 'P' &&
                s[n - 2] == 'A' &&
                s[n - 1] == 'P')
            {
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
        }
    }
    if (s == "P")
        cout << "PPAP";
    else
        cout << "NP";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}