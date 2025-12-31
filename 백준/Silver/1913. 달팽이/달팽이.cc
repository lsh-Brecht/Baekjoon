#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647
using ll = long long;
using ld = long double;
using namespace std;
class point {
public:
	int y, x;
};
int mat[1000][1000]; //0 based로 인덱스 계산 정리
void solve() {
	int N, M;
	cin >> N >> M;
	point ans{ 0, 0 }; //무지성 만들어가면서 찾아보기
	point onePosition = (N % 2)	?
		point{ N / 2, N / 2 } :
		point{ N / 2, N / 2 - 1 };
	mat[onePosition.y][onePosition.x] = 1;
	if (M == 1) ans = onePosition;
	int nextNum = 2;
	for (int i = 2; i <= N; ++i) {
		int offset = (i - 1) / 2;
		point cur = (i % 2 == 0) ?
			point{ onePosition.y - 1 - offset, onePosition.x - offset } :
			point{ onePosition.y + offset, onePosition.x + offset };
		//i가 짝수면 오른쪽 갔다가 아래로
		if (i % 2 == 0) {
			for (int j = 0; j < i; ++j) {
				if (nextNum == M) ans = point{ cur.y, cur.x + j };
				mat[cur.y][cur.x + j] = nextNum++;
			}
			cur = point{ cur.y, cur.x + i - 1 };
			for (int j = 1; j < i; ++j) {
				if (nextNum == M) ans = point{ cur.y + j, cur.x };
				mat[cur.y + j][cur.x] = nextNum++;
			}
		}
		//i가 홀수면 왼쪽 갔다가 위로
		else {
			for (int j = 0; j < i; ++j) {
				if (nextNum == M) ans = point{ cur.y, cur.x - j };
				mat[cur.y][cur.x - j] = nextNum++;
			}
			cur = point{ cur.y, cur.x - i + 1 };
			for (int j = 1; j < i; ++j) {
				if (nextNum == M) ans = point{ cur.y - j, cur.x };
				mat[cur.y - j][cur.x] = nextNum++;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans.y + 1 << ' ' << ans.x + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}