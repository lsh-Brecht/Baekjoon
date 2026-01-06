#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

vector<int> arr;
pair<int, int> sumNodeVal(pair<int, int> a, pair<int, int> b) {
	int first, second;
	if (a.first > b.first) {
		first = a.first;
		second = max(a.second, b.first);
	}
	else {
		first = b.first;
		second = max(b.second, a.first);
	}
	return { first, second };
}

class SegTree {
	int _treeLastIdx;
	vector<pair<int,int>> segTree;
private:
	void build(vector<int>& arr, int curNode, int start, int end) {
		if (start == end) {
			segTree[curNode].first = arr[start];
			segTree[curNode].second = 0;
			return;
		}
		int mid = (start + end) / 2;
		build(arr, curNode * 2, start, mid);
		build(arr, curNode * 2 + 1, mid + 1, end);
		segTree[curNode] = sumNodeVal(segTree[curNode * 2],segTree[curNode * 2 + 1]);
	}
	void update_Tree(int node, int start, int end, int idx, int val) {
		if (idx < start || end < idx) return;
		if (start == end) {
			segTree[node] = { val, 0 };
			return;
		}
		int mid = (start + end) / 2;
		update_Tree(node * 2, start, mid, idx, val);
		update_Tree(node * 2 + 1, mid + 1, end, idx, val);
		segTree[node] = sumNodeVal(segTree[node * 2], segTree[node * 2 + 1]);
	}

	pair<int,int> query_Tree(int node, int start, int end, int left, int right) {
		if (left > end || right < start) return { 0, 0 };
		if (left <= start && end <= right) return segTree[node];
		int mid = (start + end) / 2;
		return sumNodeVal(query_Tree(node * 2, start, mid, left, right),
			query_Tree(node * 2 + 1, mid + 1, end, left, right));
	}

public:
	SegTree(vector<int>& arr, int dataSize) {
		_treeLastIdx = dataSize; //1-based
		segTree.resize(dataSize * 4);
		build(arr, 1, 1, _treeLastIdx);
	}
	void update(int idx, int val) {
		update_Tree(1, 1, _treeLastIdx, idx, val);
	}
	pair<int,int> query(int left, int right) {
		return query_Tree(1, 1, _treeLastIdx, left, right);
	}
};
void solve() {

	int n, m; cin >> n;
	arr.resize(n+1);
	for (int i = 1; i <= n; ++i)cin >> arr[i];

	SegTree segtree(arr, n);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int cmd;  cin >> cmd;
		if (cmd == 1) {
			int idx; ll val; cin >> idx >> val;
			segtree.update(idx, val);
		}
		else
		{
			int left, right; cin >> left >> right;
			pair<int, int> ans = segtree.query(left, right);
			cout << (ans.first+ ans.second) << '\n';
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}