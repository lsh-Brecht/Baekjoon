#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
struct Point {
	ll x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};
struct Edge {
    int to;
    double weight;
};

int n, m;
vector<Point> citizens;
vector<int> speeds;
vector<pair<Point, Point>> occluders;
vector<Point> endPoints;
double distToBorder[102];

int ccw(Point a, Point b, Point c) {
	ll val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

bool isIntersect(Point a, Point b, Point c, Point d) {
	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);
	if (abc * abd <= 0 && cda * cdb <= 0) return true;
	return false;
}

double getDist(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool isBlocked(Point p1, Point p2) {
    for (int i = 0; i < m; ++i) {
        if ((p1 == occluders[i].first) || (p1 == occluders[i].second) ||
            (p2 == occluders[i].first) || (p2 == occluders[i].second)) continue;
        if (isIntersect(p1, p2, occluders[i].first, occluders[i].second)) return true;
    }
    return false;
}

void dijkstra() {
    int len = m * 2;
    for (int i = 0; i < len; ++i) distToBorder[i] = 1e15; // 충분히 큰 값

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    for (int i = 0; i < len; ++i) {
        //국경까지 가는 길에 장애물이 있는지 확인
        Point p = endPoints[i];
        if (!isBlocked(p, { p.x, 0 })) {
            distToBorder[i] = (double)p.y;
            pq.push({ distToBorder[i], i });
        }
    }

    //국경으로 바로 갈 수 있는 장애물의 끝점들로 다익스트라 시작
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > distToBorder[u]) continue;

        for (int v = 0; v < len; ++v) {
            if (u == v) continue;
            if (!isBlocked(endPoints[u], endPoints[v])) {
                double weight = getDist(endPoints[u], endPoints[v]);
                if (distToBorder[v] > d + weight) {
                    distToBorder[v] = d + weight;
                    pq.push({ distToBorder[v], v });
                }
            }
        }
    }
}
void solve() {
    vector<double> results;
    cin >> n >> m;
	citizens.resize(n);
	speeds.resize(n);
	occluders.resize(m);
    endPoints.resize(m * 2);
    results.resize(n);
	char c;
	for (int i = 0; i < n; ++i) {
		int a, b, v;
		cin >> c >> a >> c >> b >> c >> v;
		citizens[i] = { a, b };
		speeds[i] = v;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, q, w;
		cin >> c >> a >> c >> b >> c >> c >> c >> q >> c >> w >> c;
		Point p1 = { a, b };
		Point p2 = { q, w };
		occluders[i] = { p1,p2};
        endPoints[i * 2] = p1;
		endPoints[i * 2 + 1] = p2;
	}
    dijkstra();

    double maxTime = 0;
    for (int i = 0; i < n; ++i) {
        double minDist = 1e15;
        if (!isBlocked(citizens[i], { citizens[i].x, 0 }))
            minDist = min(minDist, (double)citizens[i].y);
        for (int j = 0; j < m * 2; ++j) {
            if (!isBlocked(citizens[i], endPoints[j])) {
                minDist = min(minDist, getDist(citizens[i], endPoints[j]) + distToBorder[j]);
            }
        }
        maxTime = max(maxTime, minDist / speeds[i]);
    }

    cout << fixed;
    cout.precision(1);
    cout << maxTime;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}