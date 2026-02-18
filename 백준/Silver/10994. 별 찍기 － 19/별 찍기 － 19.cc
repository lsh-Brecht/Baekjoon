#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
//1 5 9
//1 5 9
char mat[500][500];

void recur(int x, int s)
{
	if (x == 1)
	{
		mat[s][s] = '*';
		return;
	}
	int k = x * 4 - 3;
	for(int i=s; i<k+ s; ++i)
	{
		for(int j=s; j<k+ s; ++j)
		{
			if ((i-s) % (k - 1) == 0 || (j-s) % (k - 1) == 0)
			{
				mat[i][j] = '*';
			}
		}
	}
	recur(x - 1, s + 2);
}

void solve()
{
	int n; cin >> n;
	int k = n * 4 - 3;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			mat[i][j] = ' ';
		}
	}
	recur(n, 0);
	for(int i=0; i<k; ++i)
	{
		for(int j=0; j<k; ++j)
		{
			cout << mat[i][j];
		}
		cout << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}