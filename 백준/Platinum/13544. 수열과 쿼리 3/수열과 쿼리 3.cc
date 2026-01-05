#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int>arr;

class SegTree {
	int _treeLastIdx;
	vector<vector<int>> segTree;

private:
	void build(vector<int>& data, int node, int start, int end) {
		if (start == end) {
			segTree[node].push_back(data[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(data, node * 2, start, mid);
		build(data, node * 2 + 1, mid + 1, end);
		int len = segTree[node * 2].size();
		for(int i=0; i< len; ++i) segTree[node].push_back(segTree[node * 2][i]);
		len = segTree[node * 2 + 1].size();
		for(int i=0; i< len; ++i) segTree[node].push_back(segTree[node * 2+1][i]);
		sort(segTree[node].begin(), segTree[node].end()); //크기가 1보다 클 때만 정렬 수행하게 됨
	}
	int queryTree(int node, int start, int end, int left, int right, int k) {
		if(right < start || end < left) return 0;
		if (left <= start && end <= right) {
			//범위가 완전 포함되니 즉시 반환(lower bound가 k 이상, upper bound가 k보다 큰)
			int idx = upper_bound(segTree[node].begin(), segTree[node].end(), k) - segTree[node].begin();
			return segTree[node].size() - idx;
		}
		int mid = (start + end) / 2;
		return queryTree(node * 2, start, mid, left, right, k)
			+ queryTree(node * 2 + 1, mid+1, end, left, right, k);
	}

public:
	SegTree(vector<int>& data, int dataSize) {
		_treeLastIdx = dataSize - 1; //0-based index
		segTree.resize(dataSize * 4);
		build(data, 1, 0, _treeLastIdx);
	}
	int query(int left, int right, int val) {
		return queryTree(1, 0, _treeLastIdx, left, right, val);
	}
};

void solve() {
	int n, m; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	SegTree segtree(arr, n);
	int last_ans = 0;
	cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		//이게 왜 있는가 -> 처음에 전부 정렬해놓는 꼼수를 막기 위함.
		int left = a ^ last_ans;
		int right = b ^ last_ans;
		int val = c ^ last_ans;
		last_ans = segtree.query(left - 1, right - 1, val);
		cout << last_ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}