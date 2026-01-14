#include <iostream>
#include <vector>
#include <deque>
using namespace std; //최대한 간단히 구현
using ll = long long;

vector<int> adj[50]; //0~49
int deleteNode;

int dfs(int r){
	int cnt = 0;
	if (adj[r].empty())	return 1;
	for (int child : adj[r]) {
		if (deleteNode == child && adj[r].size() == 1) return 1;
		if (deleteNode == child) continue;
		cnt += dfs(child);
	}
	return cnt;
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
	else
		cout << dfs(root);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}