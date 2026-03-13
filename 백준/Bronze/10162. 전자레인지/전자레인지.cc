#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve()
{
    int T;
    cin >> T;
    if (T % 10 != 0)
    {
        cout << -1;
        return;
    }
    int a, b, c;
    a = T / 300;
    T %= 300;
    b = T / 60;
    T %= 60;
    c = T / 10;
    cout << a << ' ' << b << ' ' << c;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}