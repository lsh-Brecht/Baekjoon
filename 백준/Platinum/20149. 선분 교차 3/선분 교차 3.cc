#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
    bool operator<=(const Point& other) const
    {
        if (x != other.x) return x < other.x;
        return y <= other.y;
    }
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

ll ccw(Point a, Point b, Point c)
{
    ll ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}

void solve()
{
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    ll abc = ccw(A, B, C);
    ll abd = ccw(A, B, D);
    ll cda = ccw(C, D, A);
    ll cdb = ccw(C, D, B);

    bool intersect = false;

    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0)
    {
        if (B <= A) swap(A, B);
        if (D <= C) swap(C, D);
        if (A <= D && C <= B) intersect = true;
    }
    else if (abc * abd <= 0 && cda * cdb <= 0)
    {
        intersect = true;
    }
    if (!intersect)
    {
        cout << 0;
        return;
    }

    cout << 1;
    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0)
    {
        if (B == C) cout << '\n' << B.x << ' ' << B.y;
        else if (A == D) cout << '\n' << A.x << ' ' << A.y;
    }
    else
    {
        //이번에 배운 교차점 구하는 크래머 공식
        double common = ((A.x - B.x) * (C.y - D.y) - (A.y - B.y) * (C.x - D.x));
        double px = (double)((A.x * B.y - A.y * B.x) * (C.x - D.x) - (A.x - B.x) * (C.x * D.y - C.y * D.x));
        double py = (double)((A.x * B.y - A.y * B.x) * (C.y - D.y) - (A.y - B.y) * (C.x * D.y - C.y * D.x));

        cout.precision(16);
        cout << fixed << '\n' << px / common << ' ' << py / common;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}