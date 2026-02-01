#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

vector<string> StringVector;
void solve()
{
	string s; cin >> s;
	int len = (int)s.length();
	StringVector.resize(len);
	for (int i = 0; i < len; ++i)
	{
		StringVector[i] = s.substr(i, len-i);
	}
	sort(StringVector.begin(), StringVector.end());
	for (auto& str : StringVector)
	{
		cout << str << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}