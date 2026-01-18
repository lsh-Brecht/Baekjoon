#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

char mat[11][11];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
pair<int, int> player;
vector<pair<int, int>> bombs;

void solve() {
	cin >> player.first >> player.second;
	player.first--;
	player.second--;
	for (int i = 0; i < 10; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 10; ++j) {
			mat[i][j] = s[j];
			if(mat[i][j] == 'o') {
				bombs.push_back({ i, j });
			}
		}
	}
	for(auto b : bombs) {
		for (int k = 0; k < 4; ++k) {
			for (int i = 0; i < 10; ++i) {
				int nx = b.first + dx[k] * i;
				int ny = b.second + dy[k] * i;
				if (nx < 0 || nx > 9 || ny < 0 || ny > 9) break;
				mat[nx][ny] = 'o';
			}
		}
	}

	int minv = 1000;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (mat[i][j] == 'x') {
				int dist = abs(player.first - i) + abs(player.second - j);
				minv = min(minv, dist);
			}
		}
	}
	cout << minv;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}