#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

class point
{
public:
    ll x;
    ll y;
};

int CCW(point a, point b, point c)
{
    ll t1 = (a.x * b.y) + (b.x * c.y) + (c.x * a.y);
    ll t2 = (a.y * b.x) + (b.y * c.x) + (c.y * a.x);
    ll rus = t1 - t2;
    if (rus > 0)
        return 1;
    else if (rus < 0)
        return -1;
    else
        return 0;
}

void solve()
{
    point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    int ab_c = CCW(a, b, c);
    int ab_d = CCW(a, b, d);
    int cd_a = CCW(c, d, a);
    int cd_b = CCW(c, d, b);
    //점 c와 d가 선분 ab를 기준으로 서로 다른 쪽에 있고
	//마찬가지로 점 a와 b가 선분 cd를 기준으로 서로 다른 쪽에 있는 경우 교차 판정
    if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
        cout << 1;
    else
        cout << 0;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}