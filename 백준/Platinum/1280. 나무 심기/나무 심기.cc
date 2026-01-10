#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX_COORD = 200000;
const ll MOD = 1000000007;
struct Node {
	ll count;
	ll sum;
	Node() : count(0), sum(0) {}
	Node(ll c, ll s) : count(c), sum(s) {}
};

class SegmentTree {
	int _lastiIx;
	vector<Node> tree;

public:
	SegmentTree(int dz)  {
		//처음에 바로 tree를 만들지 않으니 크기만 초기화
		_lastiIx = dz;
		tree.resize(4 * _lastiIx);
	}
	void update(int idx, int val) { update(1, 0, _lastiIx, idx, val); }
	Node query(int l, int r) { return query(1, 0, _lastiIx, l, r); }

private:
	void update(int node, int start, int end, int idx, int val) {
		if (idx < start || idx > end) return;
		if (start == end) {
			tree[node].count += 1;
			tree[node].sum += val;
			return;
		}

		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, val);
		update(node * 2 + 1, mid + 1, end, idx, val);
		tree[node].count = tree[node * 2].count + tree[node * 2 + 1].count;
		tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	}

	Node query(int node, int start, int end, int l, int r) {
		if (r < start || end < l) return Node(0, 0);
		if (l <= start && end <= r) return tree[node];
		int mid = (start + end) / 2;
		Node leftTree = query(node * 2, start, mid, l, r);
		Node rightTree = query(node * 2 + 1, mid + 1, end, l, r);
		return Node(leftTree.count + rightTree.count, leftTree.sum + rightTree.sum);
	}
};

void solve() {
	int n; cin >> n;
	SegmentTree st(MAX_COORD);
	ll ans = 1;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (i > 0) {
			Node left = st.query(0, x - 1);
			ll leftCost = (x * left.count - left.sum) % MOD;
			Node right = st.query(x + 1, MAX_COORD);
			ll rightCost = (right.sum - x * right.count) % MOD;

			ll cCost = (leftCost + rightCost) % MOD;
			if (cCost < 0) cCost += MOD;
			ans = (ans * cCost) % MOD;
		}
		//현재 나무 업데이트
		st.update(x, x);
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}