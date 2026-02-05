#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
using ll = long long;

int cnt;
int recur(string& s, int l, int r)
{
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recur(s, l + 1, r - 1);
}
int isPalindrome(string& s)
{
	cnt = 0;
	return recur(s, 0, s.length() - 1);
}

void solve()
{
	int n;
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		int result = isPalindrome(s);
		cout << result << ' ' << cnt << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}