#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int mat[65][65];

bool allMatch(int y, int x, int mSize) {
	int sample = mat[y][x];
	for (int i = y; i < y + mSize; ++i) {
		for (int j = x; j < x + mSize; ++j) {
			if (mat[i][j] != sample) {
				return false;
			}
		}
	}
	return true;
}

void recur(int y, int x, int mSize) {
	bool flag = allMatch(y,x,mSize);
	if (flag) {
		cout << mat[y][x];;
		return;
	}

	int half = mSize / 2;
	cout << '(';
	recur(y, x, half);
	recur(y, x + half, half);
	recur(y + half, x, half);
	recur(y+ half, x + half, half);
	cout << ')';
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			mat[i][j] = (s[j] == '1') ? 1 : 0;
		}
	}
	recur(0,0,n);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}