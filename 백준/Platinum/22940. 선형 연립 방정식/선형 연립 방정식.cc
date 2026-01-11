#include <iostream>
using namespace std;
using ll = long long; //단순하게 가우스 소거법
void solve() {
    int N; cin >> N;
    double matrix[7][8];
    double ans[7];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= N; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= N; ++k) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < N; ++j) {
            sum += matrix[i][j] * ans[j];
        }
        ans[i] = (matrix[i][N] - sum) / matrix[i][i];
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}