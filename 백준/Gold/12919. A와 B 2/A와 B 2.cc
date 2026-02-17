#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

string S;
bool possible = false;

void dfs(string T)
{
	if (possible)
	{
		return;
	}
	if (T.length() == S.length())
	{
		if (T == S)
		{
			possible = true;
		}
		return;
	}
	if (T.back() == 'A')
	{
		string next = T.substr(0, T.length() - 1);
		dfs(next);
	}
	if (T.front() == 'B')
	{
		string next = T;
		reverse(next.begin(), next.end());
		next.pop_back();
		dfs(next);
	}
}

void solve()
{
	string T;
	cin >> S >> T;
	dfs(T);
	cout << (possible ? 1 : 0);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}