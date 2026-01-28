#include <iostream>
#include <stack>
#include <string>
using namespace std;
using ll = long long;

void solve()
{
	string s; cin >> s;
	stack<char> ctack;
	int len = s.length();
	bool lastIsOpen = false;
	int cnt = 0; //쪼개는 개수
	int stick = 0; //원래 막대기의 개수
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '(')
		{
			lastIsOpen = true;
			stick++;
			ctack.push(s[i]);
		}
		else
		{
			if (lastIsOpen)
			{
				stick--; //애는 레이저임.
				cnt += (int)ctack.size()-1;
			}
			lastIsOpen = false;
			ctack.pop();
		}
	}
	cout << stick + cnt;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}