#include <iostream>
using namespace std;
using ll = long long;
void solve()
{
    int A, B, C;
    cin >> A >> B >> C;
    int year = 1;
    while (true)
    {
        if ((year - A) % 15 == 0 && (year - B) % 28 == 0 && (year - C) % 19 == 0)
        {
            cout << year << '\n';
            break;
        }
        year++;
    }
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}