#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int N;
int pip[11];
vector<int> adj[11];

bool isitConnected(const vector<int>& group)
{
	if (group.empty())
	{
		return false;
	}
	queue<int> q;
	q.push(group[0]);
	bool visited[11] = {};
	visited[group[0]] = true;
	int count = 1;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int next : adj[curr])
		{
			bool inGroup = false;
			for (int node : group)
			{
				if (node == next)
				{
					inGroup = true;
					break;
				}
			}
			if (inGroup && !visited[next])
			{
				visited[next] = true;
				q.push(next);
				count++;
			}
		}
	}
	return count == group.size();
}
void solve()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> pip[i];

	for (int i = 1; i <= N; ++i)
	{
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; ++j)
		{
			int neighbor; cin >> neighbor;
			adj[i].push_back(neighbor);
		}
	}

	int min_diff = 1e9;
	for (int i = 1; i < (1 << N) - 1; ++i)
	{
		vector<int> groupA, groupB;
		int sumA = 0, sumB = 0;

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				groupA.push_back(j + 1);
				sumA += pip[j + 1];
			}
			else
			{
				groupB.push_back(j + 1);
				sumB += pip[j + 1];
			}
		}

		// 두 선거구 모두 연결되어 있는지 확인하고 업데이트
		if (isitConnected(groupA) && isitConnected(groupB))
		{
			min_diff = min(min_diff, abs(sumA - sumB));
		}
	}
	if (min_diff == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << min_diff;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}