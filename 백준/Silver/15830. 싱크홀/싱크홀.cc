#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve()
{
	int v, W, D;
	cin >> v >> W >> D;
	double falling = 0.0;
	double V = v;
	int count = 0;
	while (true)
	{
		//벽에 충돌할 때까지 걸리는 시간
		double t = W / V;
		double dy = 5.0 * t * t;
		//그동안 바닥까지 떨어졌다면
		if (falling + dy >= D)
		{
			break;
		}
		falling += dy;
		++count;
		V *= 0.8;
	}
	cout << count;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}