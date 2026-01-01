#include <iostream>
#include <vector>
#include <queue>
using namespace std; //topology sort는 아닌듯

vector<vector<pair<int,int>>> adj;
vector<int> dist;
vector<bool> visited;

struct comp {
	//priority queue용, lambda는 c++11부터 지원.
	//pair 순서를 바꾸는게 훨씬 간단하지만 그럴 수 없는 경우를 가정
	bool operator()(pair<int,int> &a, pair<int,int> &b) {
		if (a.second != b.second) return a.second > b.second;
		return a.first > b.first;
	}
};

pair<int,int> dijk(int s, int n) {
	int infested_Cnt = 0;
	int last_Time = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push({ s, 0});
	dist[s] = 0;
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		int cur_Node = cur.first;
		int cur_Time = cur.second;
		if (visited[cur_Node]) continue;
		visited[cur_Node] = true;
		last_Time = cur_Time;

		for (auto next : adj[cur_Node]) {
			int next_Node = next.first;
			int next_Time = next.second;
			if (cur_Time + next_Time < dist[next_Node]) {
				dist[next_Node] = cur_Time + next_Time;
				pq.push({ next_Node, cur_Time + next_Time });
			}
		}
	}
	for(int i=1; i <= n; ++i) {
		if (dist[i] != 987654321) infested_Cnt++;
	}
	return { infested_Cnt, last_Time };
}

void solve() {
	int n, d, start; cin >> n >> d >> start; //computer는 1~n
	adj.resize(n + 1);
	visited.resize(n + 1);
	dist.assign(n + 1, 987654321);
	for (int i = 0; i < d; ++i) {
		int a, b, w; cin >> a >> b >> w;
		adj[b].push_back({ a,w }); //directed
	}
	auto ans = dijk(start, n);
	cout << ans.first << ' ' << ans.second << '\n';
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int testCase; cin >> testCase;
	while (testCase--) {
		adj.clear();
		visited.clear();
		dist.clear();
		solve();
	}
	return 0;
}