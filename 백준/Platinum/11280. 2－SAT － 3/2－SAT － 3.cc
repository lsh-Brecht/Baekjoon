#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> //알고리즘 수업 정석대로 진행
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<bool> visited;
vector<int> sccArr;
stack<int> s;
int global_scc = 0;
int v, e;

bool comp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
    s.push(u);
}
void rev_dfs(int u, int sIdx) {
    visited[u] = true;
    sccArr[u] = sIdx;
    for (int v : rev_adj[u]) {
        if (!visited[v]) rev_dfs(v, sIdx);
    }
}

int makePosi(int x) {
    return x + v;
}
int notOper(int x) {
    if (x > v) return x - v;
    else return x + v;
}

void solve() {
	cin >> v >> e;
	//v는 1~10000, -v는 10001~20000
	adj.resize(v*2+2);
	rev_adj.resize(v*2+2);
	sccArr.resize(v * 2 + 2);
	for (int i = 0; i < e; ++i) {
		int a, b; cin >> a >> b;
		if (a < 0) a = makePosi(-a);
		if (b < 0) b = makePosi(-b);

		adj[notOper(a)].push_back(b);
        adj[notOper(b)].push_back(a);

        rev_adj[a].push_back(notOper(b));
        rev_adj[b].push_back(notOper(a));
	}
    visited.resize(v*2 + 2);
    for(int i=1;i<=v*2;++i) {
        if(!visited[i]) dfs(i);
	}
    visited.assign(v*2 + 2, false);
    vector<vector<int>> sccs;
    while(!s.empty()) {
        int u = s.top(); s.pop();
        if(!visited[u]) {
            rev_dfs(u, global_scc++);
        }
    }
    for (int i = 1; i <= v; i++) {
        if (sccArr[i] == sccArr[notOper(i)]) {
            cout << 0;
            return;
        }
    }
    cout << 1;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}