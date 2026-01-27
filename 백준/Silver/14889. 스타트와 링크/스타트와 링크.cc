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
    if (cnt == n / 2) {
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
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
    selected[idx] = true;
    recur(idx + 1, cnt + 1);
    selected[idx] = false;
    recur(idx + 1, cnt);
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