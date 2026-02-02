#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

//질문게시판 확인
void solve()
{
	double V, W, D;
	cin >> V >> W >> D;
    int count = 0;
    double falling = 0.0;
    double dy = 5.0L * (W / V) * (W / V);
    while (true)
    {
        if (falling + dy >= D)
        {
            break;
        }
        falling += dy;
        count++;
        dy *= 1.5625;
    }
    cout << count;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}