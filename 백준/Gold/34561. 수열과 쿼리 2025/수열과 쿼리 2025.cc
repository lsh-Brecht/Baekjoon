#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int>arr;

class UnionFind {
	int lastIdx;
	vector<int> parent;
public:
	void build(int idx) {
		parent.resize(idx + 1);
		for (int i = 1; i <= idx; ++i) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) parent[x] = y;
	}
	UnionFind(int dSize) {
		lastIdx = dSize; //1 based index
		build(lastIdx);
	}
};

int realVal[300001];
int realPos[300001];
void solve() {
    int n, m; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
    //범위는 늘 신중히
	for (int i = 1; i <= 300000; ++i) {
		realVal[i] = i;
		realPos[i] = i;
	}
	UnionFind uf(300000);

	cin >> m;
	while (m--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int x, y; cin >> x >> y; if (x == y) continue;
			if (realPos[x] == 0) continue;
			if (realPos[y] == 0) {
				realPos[y] = realPos[x];
				realVal[realPos[y]] = y;
				realPos[x] = 0;
			}
			else {
				uf.merge(realPos[x], realPos[y]);
				realPos[x] = 0;
			}
		}
		else {
			int z; cin >> z;
			cout << realVal[uf.find(arr[z - 1])] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}