#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
//문제유형 확인, 백트랙킹.
int n;
int allComb[21][21];
bool selected[21];
int ans = 500000;

void recur(int idx, int cnt) {
    if (ans == 0) return;//0이 발견되었다면 싹 다 가지치기
    if (cnt == n / 2) {
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (selected[i] && selected[j]) {
                    t1 += allComb[i][j] + allComb[j][i];
                }
                else if (!selected[i] && !selected[j]) {
                    t2 += allComb[i][j] + allComb[j][i];
                }
            }
        }
        ans = min(ans, abs(t1 - t2));
        return;
    }
    if (idx == n) return;
    for (int i = idx; i < n; ++i) {
        if (cnt == 0 && i > 0) return;
        selected[i] = true;
        recur(i + 1, cnt + 1);
        selected[i] = false;
    }
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> allComb[i][j];
	recur(0, 0);
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}