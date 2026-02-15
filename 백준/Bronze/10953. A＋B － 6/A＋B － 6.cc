#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

void solve()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << s[0]-'0'+ s[2] - '0' << '\n';
	}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}