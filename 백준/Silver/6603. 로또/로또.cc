#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
vector<int> arr;
vector<int> pick;

void recur(int start, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << pick[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        pick[cnt] = arr[i];
        recur(i + 1, cnt + 1);
    }
}

void solve() {
	while (true) {
		n; cin >> n; if (n == 0) break;
		arr.resize(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		//오름차순으로 입력되니 sort 필요 없음.
        pick.resize(6);
        recur(0, 0);
        cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}