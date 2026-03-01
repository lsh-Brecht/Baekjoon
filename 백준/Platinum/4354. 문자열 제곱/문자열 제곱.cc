#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

//전형적인 kmp-실패함수 문제
vector<int> failFunc(string& p)
{
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
        {
            pi[i] = ++j;
        }
    }
    return pi;
}

void solve()
{
    while(true)
    {
		string s; cin >> s;
        if (s == ".")
        {
            break;
        }
        vector<int> pi = failFunc(s);
        int n = s.size();
        int len = n - pi[n - 1];
        if (n % len == 0)
        {
            cout << n / len << '\n';
        }
        else
        {
            cout << 1 << '\n';
		}
    }
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}