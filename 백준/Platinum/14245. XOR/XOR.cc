#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> arr;

class SegTree {
	int treeLastIdx;
	vector<int> segTree;
	vector<int> lazyTree;
private:
	void build(vector<int>& arr, int node, int start, int end) {
		if(start == end) {
			segTree[node] = arr[start];
			return;
		}
		int mid = (start + end) / 2;
		build(arr, node * 2, start, mid);
		build(arr, node * 2+1, mid+1, end);
		segTree[node] ^= (segTree[node * 2] ^ segTree[node * 2 + 1]);
	}

	void update_Tree(int node, int start, int end, int left, int right, int xorval) {
		if (right < start || end < left) return;
		propagate(node, start, end);
		if (left <= start && end <= right) {
			lazyTree[node] ^= xorval;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		update_Tree(node * 2, start, mid, left, right, xorval);
		update_Tree(node * 2+1, mid + 1, end , left, right, xorval);
		segTree[node] = segTree[node * 2] ^ segTree[node * 2 + 1];
	}

	int query_Tree(int node, int start, int end, int idx) {
		propagate(node, start, end);
		if (idx < start || end < idx) return 0;
		if(idx == start && end == idx) {
			return segTree[node];
		}
		int mid = (start + end) / 2;
		return (idx <= mid) ? query_Tree(node * 2, start, mid, idx) : query_Tree(node * 2 + 1, mid + 1, end, idx);
	}
	void propagate(int node, int start, int end) {
		if (lazyTree[node] != 0) {
			if ((end - start + 1) % 2)
				segTree[node] ^= lazyTree[node];
			if (end != start) {
				lazyTree[node * 2] ^= lazyTree[node];
				lazyTree[node * 2 + 1] ^= lazyTree[node];
			}
			lazyTree[node] = 0;
		}
	}

public:
	SegTree(vector<int>& arr, int dSize) {
		treeLastIdx = dSize - 1;
		segTree.resize(dSize * 4);
		lazyTree.resize(dSize * 4);
		build(arr, 1, 0, treeLastIdx);
	}
	void update(int left, int right, int xorval) {
		update_Tree(1, 0, treeLastIdx, left, right, xorval);
	}
	int query(int idx) {
		return query_Tree(1, 0, treeLastIdx, idx);
	}
};
void solve() {
	int n,m; cin >> n;
	arr.resize(n);//0-based
	for (int i = 0; i < n; ++i)cin >> arr[i];
	SegTree segTree(arr, n);
	cin >> m;
	while (m--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			//update
			int left, right, xorval;
			cin >> left >> right >> xorval;
			segTree.update(left, right, xorval);
		}
		else {
			//query
			int idx;
			cin >> idx;
			cout << segTree.query(idx) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}