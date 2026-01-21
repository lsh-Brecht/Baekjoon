#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> arr;
void solve() {
    int k, n; cin >> k >> n; arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int maxv = k;
    int minv = k;

    for (int x : arr) {
        if (x <= maxv) {
            maxv++;
        }
    }

    int i = 1;
    for (int x : arr) {
        if (x < minv) {
            minv++;
        }
        else if (x == minv) {
            i++;
        }
        else if (x < minv + i) {
            int temp = minv + i;
            minv = x;
            i = temp - x + 1;
        }
    }
    cout << minv << ' ' << maxv;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}