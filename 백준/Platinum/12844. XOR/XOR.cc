#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> arr;
class SegTree {
	int _TreeLastIdx;
	vector<int> segTree;
	vector<int> lazyTree;

private:
	void build(vector<int>& data, int node, int start, int end) {
		if (start == end) {
			segTree[node] = data[start]; // segTree[start] = data[start]; 치명적인 실수
			return;
		}
		int mid = (start + end) / 2;
		build(data, node * 2, start, mid);
		build(data, node * 2 + 1, mid + 1, end);
		segTree[node] = segTree[node * 2] ^ segTree[node * 2 + 1];
	}

	void update_Tree(int node, int start, int end, int left, int right, int xorval) {
		propagate(node, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			lazyTree[node] ^= xorval;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		update_Tree(node * 2, start, mid, left, right, xorval);
		update_Tree(node * 2 + 1, mid + 1, end, left, right, xorval);
		segTree[node] = segTree[node * 2] ^ segTree[node * 2 + 1];
	}

	int query_Tree(int node, int start, int end, int left, int right) {
		propagate(node, start, end);
		if (right < start || end < left) return 0; //A^0=A
		if (left <= start && end <= right)
			return segTree[node];
		int mid = (start + end) / 2;
		return query_Tree(node * 2, start, mid, left, right) ^ query_Tree(node * 2 + 1, mid + 1, end, left, right);
	}

	void propagate(int node, int left, int right) {
		if (lazyTree[node] != 0) {
			//xor이므로 홀 수개의 구간이 주어져야 함
			if ((right - left + 1) % 2)
				segTree[node] = segTree[node] ^ lazyTree[node];
			if (left != right) {
				lazyTree[node * 2] ^= lazyTree[node];
				lazyTree[node * 2 + 1] ^= lazyTree[node];
			}
			lazyTree[node] = 0;
		}
	}

public:
	SegTree(vector<int>& data, int treeSize) {
		_TreeLastIdx = treeSize - 1;
		segTree.resize(treeSize * 4);
		lazyTree.resize(treeSize * 4);
		build(data, 1, 0, _TreeLastIdx);
	}
	void update(int left, int right, int xorval) {
		update_Tree(1, 0, _TreeLastIdx, left, right, xorval);
	}
	int query(int left, int right) {
		return query_Tree(1, 0, _TreeLastIdx, left, right);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	SegTree segTree(arr, n);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			//이미 0 based index
			//xor update
			int left, right, xorval;
			cin >> left >> right >> xorval;
			segTree.update(left, right, xorval);
		}
		else {
			//xor query
			int left, right;
			cin >> left >> right;
			cout << segTree.query(left, right) << '\n';
		}
	}
	return 0;
}