#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
using ll = long long;

int mat[2200][2200];
int ans[3];
void recur(int y, int x, int size)
{
	int first = mat[y][x];
	if(size == 1)
	{
		++ans[first + 1];
		return;
	}
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (mat[i][j] != first)
			{
				int newSize = size / 3;
				recur(y, x, newSize);
				recur(y, x + newSize, newSize);
				recur(y, x + 2 * newSize, newSize);

				recur(y + newSize, x, newSize);
				recur(y + newSize, x + newSize, newSize);
				recur(y + newSize, x + 2 * newSize, newSize);

				recur(y + 2 * newSize, x, newSize);
				recur(y + 2 * newSize, x + newSize, newSize);
				recur(y + 2 * newSize, x + 2 * newSize, newSize);
				return;
			}
		}
	}
	++ans[first + 1];
}

void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}
	recur(0, 0, n);
	for (int i = 0; i < 3; ++i)
	{
		cout << ans[i] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}