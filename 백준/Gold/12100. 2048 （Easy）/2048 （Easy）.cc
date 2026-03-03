#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue> //이 문제를 드디어 푸네
using namespace std;
using ll = long long;

int n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
enum DIR { UP, DOWN, LEFT, RIGHT };;
struct mat
{
	int cnt;
	int maxv;
	int matrix[20][20];
};
mat moving(mat m, int dir)
{
    // 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    for (int k = 0; k < n; ++k)
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            int r, c;
            if (dir == UP)
            {
                r = i; c = k;
            }
            else if (dir == DOWN)
            {
                r = n - 1 - i; c = k;
            }
            else if (dir == LEFT)
            {
                r = k; c = i;
            }
            else
            {
                r = k; c = n - 1 - i;
            }
            if (m.matrix[r][c] != 0)
            {
                v.push_back(m.matrix[r][c]);
                m.matrix[r][c] = 0;
            }
        }
        vector<int> merged;
		int vlen = v.size();
        for (int i = 0; i < vlen; ++i)
        {
            if (i + 1 < vlen && v[i] == v[i + 1])
            {
                merged.push_back(v[i] * 2);
                i++;
            }
            else
            {
                merged.push_back(v[i]);
            }
        }
		int mlen = merged.size();
        for (int i = 0; i < mlen; ++i)
        {
            int r, c;
            if (dir == UP)
            {
                r = i; c = k;
            }
            else if (dir == DOWN)
            {
                r = n - 1 - i; c = k;
            }
            else if (dir == LEFT)
            {
                r = k; c = i; }
            else
            {
                r = k; c = n - 1 - i;
            }
            m.matrix[r][c] = merged[i];
        }
    }

    int cur_max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cur_max = max(cur_max, m.matrix[i][j]);
    m.maxv = cur_max;

    return m;
}

queue<mat> q;
void solve()
{
	cin >> n;
	mat start;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		for (int j = 0; j < n; ++j)
		{
			cin >> temp;
			start.matrix[i][j] = temp;
		}
	}
	start.cnt = 0;
	q.push(start);
	int maxv = -1;
	while (!q.empty())
	{
		mat cur = q.front(); q.pop();
        //이전걸 꺼내서 4방향으로 움직여보고 업데이트 후 다시 넣기
		for (int i = 0; i < 4; ++i)
		{
			mat ret = moving(cur, i);
			maxv = max(maxv, ret.maxv);
			ret.cnt = cur.cnt + 1;
			if (ret.cnt <5) q.push(ret);
		}
	}
	cout << maxv;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}