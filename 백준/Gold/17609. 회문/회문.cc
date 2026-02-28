#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

bool partialsolve(string& s, int left, int right)
{
	while (left < right)
	{
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
}

void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
        string s;
        cin >> s;
        int pLeft = 0, pRight = s.length() - 1;
        int ans = 0;
        while (pLeft < pRight)
        {
            if (s[pLeft] != s[pRight])
            {
                if (partialsolve(s, pLeft + 1, pRight) || partialsolve(s, pLeft, pRight - 1))
                {
                    ans = 1;
                }
                else
                {
                    ans = 2;
                }
                break;
            }
            pLeft++;
            pRight--;
        }
        cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}