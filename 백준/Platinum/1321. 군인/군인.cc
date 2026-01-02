#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

class SegTree {
	int _treeLastIdx;
	vector<int> segTree;
	
private:
	void build(vector<int>& arr, int curNode, int start, int end) {
		if (start == end) {
			segTree[curNode] = arr[start];
			return;
		}
		int mid = (start + end) / 2;
		build(arr, curNode*2, start, mid);
		build(arr, curNode*2+1, mid+1, end);
		segTree[curNode] = segTree[curNode * 2] + segTree[curNode * 2 + 1];
	}
	
	void up_Tree(int node, int start, int end, int idx, int val) {
		if (idx < start || end < idx) return;
		if(start == end) {
			segTree[node] += val;
			return;
		}
		int mid = (start + end) / 2;
		up_Tree(node * 2, start, mid, idx, val);
		up_Tree(node * 2+1, mid+1, end, idx, val);
		segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
	}

	int query_Tree(int node, int start, int end, int x) {
		if (start == end) {
			return start;
		}
		int mid = (start + end) / 2;
		if (x <= segTree[node * 2])
			return query_Tree(node * 2, start, mid, x);
		else
			return query_Tree(node * 2 + 1, mid + 1, end, x - segTree[node * 2]);
	}

public:
	SegTree(vector<int>& arr, int dataSize) {
		_treeLastIdx = dataSize; //1-based
		segTree.resize(dataSize * 4);
		build(arr, 1, 1, _treeLastIdx);
	}
	void update(int idx, int val) {
		up_Tree(1, 1, _treeLastIdx, idx, val);
	}
	int query(int idx) {
		return query_Tree(1, 1, _treeLastIdx, idx);
	}
};

void solve() {
	int n, m; cin >> n;
	arr.resize(n+1);
	for (int i = 1; i <= n; ++i)cin >> arr[i];
	SegTree segTree(arr, n);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int idx, val; cin >> idx >> val;
			segTree.update(idx, val);
		}
		else {
			int idx; cin >> idx;
			cout <<segTree.query(idx) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}