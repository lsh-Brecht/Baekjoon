#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
using ll = long long;

class Point
{
public:
	int x, y;
};

//3차원 외적을 행렬식처럼 계산
int ccw(Point p1, Point p2, Point p3)
{
	int area = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	if (area > 0) return 1;
	else if (area < 0) return -1;
	else return 0;
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4)
{
	int res1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int res2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if (res1 == 0 && res2 == 0)
	{
		//일직선 상에 있으면서 겹치는지 확인
		if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p3.x, p4.x) < min(p1.x, p2.x)) return false;
		if (max(p1.y, p2.y) < min(p3.y, p4.y) || max(p3.y, p4.y) < min(p1.y, p2.y)) return false;
		return true;
	}
	return res1 <= 0 && res2 <= 0;
}

void solve()
{
    Point p1, p2, r1, r2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> r1.x >> r1.y >> r2.x >> r2.y;
    //두 좌표가 순서 없이 들어오니 입력을 받고 나서 결정
    int minX = min(r1.x, r2.x);
    int maxX = max(r1.x, r2.x);
    int minY = min(r1.y, r2.y);
    int maxY = max(r1.y, r2.y);

    if (p1.x >= minX && p1.x <= maxX && p1.y >= minY && p1.y <= maxY ||
        p2.x >= minX && p2.x <= maxX && p2.y >= minY && p2.y <= maxY)
    {
        cout << "T" << '\n';
        return;
    }
    Point lb = { minX, minY }, lt = { minX, maxY }, rb = { maxX, minY }, rt = { maxX, maxY };

    if (isIntersect(p1, p2, lt, rt) || isIntersect(p1, p2, lb, rb) ||
        isIntersect(p1, p2, lt, lb) || isIntersect(p1, p2, rt, rb))
    {
        cout << "T" << '\n';
    }
    else
    {
        cout << "F" << '\n';;
    }
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--)
    {
    	solve();
    }
	return 0;
}