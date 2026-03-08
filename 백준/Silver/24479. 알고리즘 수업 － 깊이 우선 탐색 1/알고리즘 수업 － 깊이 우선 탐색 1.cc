#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int n, m, r;
vector<int> adj[100005];
int visited[100005];
int cur = 1;

void dfs(int x)
{
    visited[x] = cur++;
    for (int cur : adj[x])
    {
        if (visited[cur] == 0)
        {
            dfs(cur);
        }
    }
}

void solve()
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(r);
    for (int i = 1; i <= n; ++i)
    {
        cout << visited[i] << '\n';
    }
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}