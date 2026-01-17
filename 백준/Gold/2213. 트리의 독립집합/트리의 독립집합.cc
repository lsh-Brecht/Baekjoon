#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int DP[100002][2];
vector<int> graphPoint;
vector<int> adj[100002];
vector<int> selected;

void dfs(int node, int prev) {
	//현재 노드를 선택하는 경우
	DP[node][1] = graphPoint[node];
	//선택하지 않는 경우
	DP[node][0] = 0;
	for (int next : adj[node]) {
		if (next == prev) continue;
		dfs(next, node); //자식 노드 탐색하고 나서
		DP[node][1] += DP[next][0];
		DP[node][0] += max(DP[next][0], DP[next][1]);
	}
}

void trace(int node, int prev, bool pSelect) {
	bool curSelected = false;
	if (pSelect) curSelected = false;
	else {
		//부모는 선택하지 않고, 나를 선택하는 게 더 큰 경우
		if (DP[node][1] > DP[node][0])
			curSelected = true;
	}
	if (curSelected)
		selected.push_back(node);
	for (int next : adj[node]) {
		if (next == prev) continue;
		trace(next, node, curSelected);
	}
}

void solve() {
	int n; cin >> n;
	graphPoint.resize(n+1); //1~n
	for(int i=0; i < n; ++i) cin >> graphPoint[i+1];
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	trace(1, 0, false);
	sort(selected.begin(), selected.end());
	cout << max(DP[1][0], DP[1][1]) << '\n';
	for (auto v : selected) cout << v << ' ';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}