#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
char mat[10][10];
bool visited[10][10][10][10];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

class Pos {
public:
	int red_y, red_x, blue_y, blue_x, moveCnt;
	Pos(int _ry, int _rx, int _by, int _bx, int _cnt)
		: red_y(_ry), red_x(_rx), blue_y(_by), blue_x(_bx), moveCnt(_cnt) {}
};

pair<pair<int, int>, int> move_ball(int y, int x, int dir) {
	int dist = 0;
	while (mat[y + dy[dir]][x + dx[dir]] != '#' && mat[y][x] != 'O') {
		y += dy[dir];
		x += dx[dir];
		dist++;
	}
	return { {y, x}, dist };
}

int bfs(Pos Balls) {
	queue<Pos> q; //red, blue, move count
	q.push(Balls);
	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		if (cur.moveCnt >= 10) break;

		for (int i = 0; i < 4; ++i) {
			auto next_red = move_ball(cur.red_y, cur.red_x, i);
			auto next_blue = move_ball(cur.blue_y, cur.blue_x, i);

			int nry = next_red.first.first;
			int nrx = next_red.first.second;
			int nby = next_blue.first.first;
			int nbx = next_blue.first.second;

			if (mat[nby][nbx] == 'O') continue; //파란공은 들어가면 안 됨
			if (mat[nry][nrx] == 'O') return cur.moveCnt + 1;

			//둘이 겹치는 경우(더 멀리 이동한 애를 한 칸 뒤로 미룸)
			//물리적으로 쌓이는 개념
			if (nry == nby && nrx == nbx) {
				if (next_red.second > next_blue.second) {
					nry -= dy[i]; nrx -= dx[i];
				}
				else {
					nby -= dy[i]; nbx -= dx[i];
				}
			}

			if (!visited[nry][nrx][nby][nbx]) {
				visited[nry][nrx][nby][nbx] = true;
				Pos next_pos(nry, nrx, nby, nbx, cur.moveCnt + 1);
				q.push(next_pos);
			}
		}
	}
	return -1;
}

void solve() {
	int n, m; cin >> n >> m; //세로 및 가로
	int red_y, red_x, blue_y, blue_x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'R') {
				red_y = i;
				red_x = j;
			}
			else if (mat[i][j] == 'B') {
				blue_y = i;
				blue_x = j;
			}
		}
	}
	Pos Balls(red_y, red_x, blue_y, blue_x, 0);
	int ret = bfs(Balls);
	cout << ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}