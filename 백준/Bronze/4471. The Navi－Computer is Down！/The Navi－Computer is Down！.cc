#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

struct Point {
	double x, y,z ;
};
double getDist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

void solve() {
	int t; cin >> t;
	cin.ignore();
	while (t--) {
		string s1, s2;
		double a, b, c;

		getline(cin, s1);
		cin >> a >> b >> c;
		Point p1 = { a, b, c };
		cin.ignore();

		getline(cin, s2);
		cin >> a >> b >> c;
		Point p2 = { a, b, c };
		cin.ignore();

		cout << fixed;
		cout.precision(2);
		cout << s1 << " to " << s2 << ": " << getDist(p1, p2) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}