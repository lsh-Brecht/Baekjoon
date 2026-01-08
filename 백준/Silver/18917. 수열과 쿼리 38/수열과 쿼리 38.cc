#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
    int Q; (cin >> Q);
    ll cSum = 0;
    int cXor = 0;
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            cSum += x;
            cXor ^= x;
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            cSum -= x;
            cXor ^= x;
        }
        else if (cmd == 3) {
            cout << cSum << '\n';
        }
        else if (cmd == 4) {
            cout << cXor << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}