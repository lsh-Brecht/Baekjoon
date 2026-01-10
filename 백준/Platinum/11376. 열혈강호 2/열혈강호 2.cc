#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<vector<int>> workerCanThis;
vector<bool> visited;
vector<int> jobsAssign;

bool dfs(int cur) {
	for(auto& job : workerCanThis[cur]) {
		if (visited[job]) continue;
		visited[job] = true;
		if (!jobsAssign[job] || dfs(jobsAssign[job])) {
			jobsAssign[job] = cur;
			return true;
		}
	}
	return false;
}
void solve() {
	int n, m; cin >> n >>m;
	workerCanThis.resize(n + 1); // 1~n
	visited.resize(m + 1); // 1~m
	jobsAssign.assign(m + 1, 0);
	for (int i = 1; i <= n; ++i) {
		int jobNum, job; cin >> jobNum;
		for (int j = 0; j < jobNum; ++j) {
			cin >> job;
			workerCanThis[i].push_back(job);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 1; k <= m; ++k) visited[k] = false;
			if (dfs(i)) ans++;
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}