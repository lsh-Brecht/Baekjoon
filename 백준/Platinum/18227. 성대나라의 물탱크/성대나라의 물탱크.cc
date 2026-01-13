#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

int n, root, q;
int in[200001], out[200001];
int timer = 0;
vector<int> adj[200001];
ll depth[200001];
ll tree[200001];

//펜윅
void update(int i, int x) {
	while (i <= n) {
		tree[i] += x;
		i += (i & -i);
	}
}
ll query(int i) {
	ll x = 0;
	while (i > 0) {
		x += tree[i];
		i -= (i & -i);
	}
	return x;
}

//오일러 경로 테크닉 - 트리를 1차원 배열로 변환
void dfs(int curr, int prev, int d) {
	in[curr] = ++timer;
	depth[curr] = d;
	for (int next : adj[curr]) {
		if (next != prev) {
			dfs(next, curr, d + 1);
		}
	}
	out[curr] = timer;
}

void solve() {
	cin >> n >> root; //1 ~ n
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(root, 0, 1);

	cin >> q;
	while (q--) {
		int type, x;
		cin >> type >> x;
		if (type == 1) {
			update(in[x], 1);
		}
		else {
			//업데이트 횟수 합 * A의 깊이
			ll cnt = query(out[x]) - query(in[x] - 1);
			cout << cnt * depth[x] << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}