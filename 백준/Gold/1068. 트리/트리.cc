#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

vector<int> adj[50]; //0~49
int deleteNode;
int ans = 0;

void dfs(int r){
	if (r == deleteNode)	return;
	int cnt = 0;
	for (int child : adj[r]) {
		if (deleteNode != child) {
			dfs(child);
			cnt++;
		}
	}
	if (cnt == 0) ans++;
}
void solve() {
	int n; cin >> n;
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int parent; cin >> parent;
		if (parent != -1)
			adj[parent].push_back(i);
		else
			root = i;
	}
	cin >> deleteNode;
	if (deleteNode == root)
		cout << 0;
	else {
		dfs(root);
		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}