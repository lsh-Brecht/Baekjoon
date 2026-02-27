#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

struct Class
{
	int start, end;
};
bool compare(Class& a, Class& b)
{
	if (a.start == b.start)
	{
		return a.end < b.end;
	}
	return a.start < b.start;
}
vector<Class> classes;
priority_queue<int, vector<int>, greater<int>> pq;
void solve()
{
	int n; cin >> n;
	classes.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> classes[i].start >> classes[i].end;
	}
	sort(classes.begin(), classes.end(), compare);

	pq.push(classes[0].end);
	for (int i = 1; i < n; ++i)
	{
		if (classes[i].start >= pq.top())
		{
			pq.pop();
		}
		pq.push(classes[i].end);
	}
	cout << (int)pq.size();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}