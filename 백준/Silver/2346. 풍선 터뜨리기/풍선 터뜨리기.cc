#include <iostream>
#include <deque>
#include <vector>
using namespace std;
//덱을 이용해 원형 큐 구현.
void solve() {
    int n; cin >> n;
    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dq.push_back({ i, x });
    }
    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();

        int idx = cur.first;
        int move = cur.second;
        cout << idx << ' ';
        if (dq.empty()) break;
        if (move > 0) {
            for (int i = 0; i < move - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int i = 0; i < -move; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}