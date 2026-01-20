#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int arr[1002][5];
void solve() {
	//30의 배수라면 3의 배수이면서 0이 하나라도 포함되어야 함.
	string s; cin >> s;
	int len = s.length();
	int sumv = 0;
	for (int i = 0; i < len; ++i) sumv += (s[i] - '0');
	if (sumv % 3 != 0) {
		cout << -1; return;
	}
	sort(s.begin(), s.end(), greater<>());
	if (s[len-1] != '0') {
		cout << -1; return;
	}
	cout << s;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}