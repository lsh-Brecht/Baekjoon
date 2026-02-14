#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

void recur(string& s, int start, int len)
{
    if (len == 1) return;
    int third = len / 3;
    for (int i = start + third; i < start + 2 * third; ++i)
    {
        s[i] = ' ';
    }
    recur(s, start, third);
    recur(s, start + 2 * third, third);
}

void solve()
{
    int N;

    while (cin >> N)
    {
        int len = pow(3, N);
        string s(len, '-'); //string 초기화 방법
        recur(s, 0, len);
        cout << s <<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}