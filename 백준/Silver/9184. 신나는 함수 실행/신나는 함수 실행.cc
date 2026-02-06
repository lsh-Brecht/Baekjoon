#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
using ll = long long;

int memo[21][21][21];
int recur(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
	{
		return recur(20, 20, 20);
	}

	int& ret = memo[a][b][c];
	if (ret != 0)
		return ret;

	if (a < b && b < c)
	{
		ret = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);
	}
	else
	{
		ret = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);
	}
	return ret;
}

void solve()
{
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a, b, c) << '\n';
	}

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}