#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
using ll = long long;

void solve()
{
	string s; getline(cin, s);
	stack<char> tack;
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '<')
		{
			while (!tack.empty())
			{
				cout << tack.top();
				tack.pop();
			}
			while(s[i] != '>')
			{
				cout << s[i];
				++i;
			}
			cout << '>';
		}
		else if (s[i] == ' ')
		{
			while (!tack.empty())
			{
				cout << tack.top();
				tack.pop();
			}
			cout << ' ';
		}
		else
			tack.push(s[i]);
	}
	while (!tack.empty())
	{
		cout << tack.top();
		tack.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}