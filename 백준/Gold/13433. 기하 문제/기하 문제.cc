#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
using ll = long long;

double radii[8];
double use[8];
double minv = numeric_limits<double>::max();;
bool visited[8];

double get_distance(int n) {
    vector<double> x(n);
    x[0] = 0.0;
    for (int i = 1; i < n; ++i) {
        double maxv = 0.0;
        for (int j = 0; j < i; ++j) {
            double dist = x[j] + 2.0 * sqrt(use[j] * use[i]);
            if (dist > maxv) {
                maxv = dist;
            }
        }
        x[i] = maxv;
    }
    return x[n - 1];
}

void bk(int count, int n) {
    if (count == n) {
        double result = get_distance(n);
        if (result < minv) minv = result;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            use[count] = radii[i];
            bk(count + 1, n);
            visited[i] = false;
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> radii[i];
    bk(0, n);
    cout << fixed << setprecision(16);
    cout << minv;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}