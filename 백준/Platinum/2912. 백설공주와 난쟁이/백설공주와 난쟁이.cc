#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //mo's algorithm
using namespace std;
using ll = long long;

int N, C, Q;
vector<int> arr;
vector<vector<int>> positions;

class SegmentTree {
public:
	struct Node {
		int candidate;
		int cnt;
		Node() : candidate(0), cnt(0) {}
		Node(int cand, int cnt) : candidate(cand), cnt(cnt) {}
	};

private:
	int lastTreeIdx;
	vector<Node> tree;
	vector<int>& treeData;

	Node mergeNode(const Node& left, const Node& right) {
		if (left.candidate == right.candidate) {
			return Node(left.candidate, left.cnt + right.cnt);
		}
		if (left.cnt > right.cnt) {
			return Node(left.candidate, left.cnt - right.cnt);
		}
		return Node(right.candidate, right.cnt - left.cnt);
	}

	void build(int node, int start, int end) {
		if (start == end) {
			tree[node] = Node(treeData[start], 1);
			return;
		}
		int mid = (start + end) / 2;
		build(node * 2, start, mid);
		build(node * 2 + 1, mid + 1, end);
		tree[node] = mergeNode(tree[node * 2], tree[node * 2 + 1]);
	}

	Node queryTree(int node, int start, int end, int l, int r) {
		if (r < start || end < l) return Node(0, 0);
		if (l <= start && end <= r) return tree[node];
		int mid = (start + end) / 2;
		return mergeNode(queryTree(node * 2, start, mid, l, r),
			queryTree(node * 2 + 1, mid + 1, end, l, r));
	}

public:
	SegmentTree(vector<int>& data) : treeData(data) {
		lastTreeIdx = data.size() - 1;
		tree.resize(4 * lastTreeIdx);
		build(1, 1, lastTreeIdx);
	}
	Node query(int l, int r) {
		return queryTree(1, 1, lastTreeIdx, l, r);
	}
};

bool isMorethanHalf(int color, int l, int r) {
	vector<int>& v = positions[color];
	int actualCount = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
	return actualCount > (r - l + 1) / 2;
}

void solve() {
	cin >> N >> C;
	arr.resize(N + 1);
	positions.resize(C + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		positions[arr[i]].push_back(i);
	}
	SegmentTree st(arr);
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		SegmentTree::Node res = st.query(a, b);
		if (res.candidate != 0 && isMorethanHalf(res.candidate, a, b)) {
			cout << "yes " << res.candidate << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}