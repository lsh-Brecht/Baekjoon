#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

//세그먼트 트리 각 노드에 벡터를 저장
class SegTree
{
	int _treeLastIdx;
	vector<vector<int>> segTree;

private:
	void build(vector<int>& data, int node, int start, int end)
	{
		if (start == end)
		{
			segTree[node].push_back(data[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(data, node * 2, start, mid);
		build(data, node * 2 + 1, mid + 1, end);

		int len = segTree[node * 2].size();
		for (int i = 0; i < len; ++i) segTree[node].push_back(segTree[node * 2][i]);
		len = segTree[node * 2 + 1].size();
		for (int i = 0; i < len; ++i) segTree[node].push_back(segTree[node * 2 + 1][i]);
		sort(segTree[node].begin(), segTree[node].end());
	}
	int queryTree(int node, int start, int end, int left, int right, int val)
	{
		if (right < start || end < left) return 0;
		if (left <= start && end <= right)
		{
			return upper_bound(segTree[node].begin(), segTree[node].end(), val) - segTree[node].begin();
		}
		int mid = (start + end) / 2;
		return queryTree(node * 2, start, mid, left, right, val)
			+ queryTree(node * 2 + 1, mid + 1, end, left, right, val);
	}

public:
	SegTree(vector<int>& data, int dataSize)
	{
		_treeLastIdx = dataSize - 1;
		segTree.resize(dataSize * 4);
		build(data, 1, 0, _treeLastIdx);
	}
	int query(int left, int right, int val)
	{
		return queryTree(1, 0, _treeLastIdx, left, right, val);
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> data(n);
	vector<int> sortedData(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> data[i];
		sortedData[i] = data[i];
	}
	SegTree st(data, n);
	sort(sortedData.begin(), sortedData.end());
	for (int i = 0; i < m; ++i)
	{
		int l, r, k;
		cin >> l >> r >> k;

		int low = 0, high = n - 1;
		int ans = 0;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int midVal = sortedData[mid];

			if (st.query(l - 1, r - 1, midVal) >= k)
			{
				ans = midVal;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}