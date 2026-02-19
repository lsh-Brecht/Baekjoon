#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
int N, M;
int r, c, d;
int board[51][51];

//북 동 남 서 시계방향
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

void solve()
{
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }
    int cnt = 0;
    while (true)
    {
        if (board[r][c] == 0)
        {
            board[r][c] = 2;
            cnt++;
        }
        bool uncleaned = false;
        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M)
            {
                if (board[nr][nc] == 0)
                {
                    uncleaned = true;
                    break;
                }
            }
        }

        if (!uncleaned)
        {
            int back_d = (d + 2) % 4; //뒤쪽
            int br = r + dr[back_d];
            int bc = c + dc[back_d];

            if (br >= 0 && br < N && bc >= 0 && bc < M && board[br][bc] != 1)
            {
                r = br;
                c = bc;
            }
            else
            {
                break;
            }
        }
        else
        {
            //청소되지 않은 곳이 있으므로 회전
            d = (d + 3) % 4;
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && board[nr][nc] == 0)
            {
                r = nr;
                c = nc;
            }
        }
    }

    cout << cnt;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}