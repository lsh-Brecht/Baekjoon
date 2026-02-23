#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

vector<int> row, col;
int mat[1001][1001];

void solve()
{
	int n, m; cin >> n >> m;
	string s;
	row.resize(n);
	col.resize(m);
	int maxv = -987654321;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < m; ++j)
		{
			mat[i][j] = s[j];
			if (s[j] == '+')
			{
				row[i]++;
				col[j]++;
			}
			else if (s[j] == '-')
			{
				row[i]--;
				col[j]--;
			}
			else
			{
				row[i]++;
				col[j]--;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int curv = row[i] - col[j];
			if (mat[i][j] == '?')
			{
				curv -= 2;
			}
			maxv = max(maxv, curv);
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