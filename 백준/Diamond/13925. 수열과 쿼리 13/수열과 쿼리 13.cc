#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>//곱과 더하기를 쌍으로 관리
using namespace std;
using ll = long long;
#define mod 1000000007
vector<int> arr;

class SegTree {
	int _treeLastIdx;
	vector<ll> segTree;
	vector<pair<ll, ll>> lazyTree; //first: multiply, second: add
private:
	void build(vector<int>& data, int node, int start, int end) {
		if (start == end) {
			segTree[node] = data[start];
			return;
		}
		int mid = (start + end) / 2;
		build(data, node * 2, start, mid);
		build(data, node * 2 + 1, mid + 1, end);
		segTree[node] = (segTree[node * 2] + segTree[node * 2 + 1] )% mod;
	}

	void updateTreeAdd(int node, int start, int end, int left, int right, int val) {
		propagate(node, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			lazyTree[node].second = (lazyTree[node].second + val) % mod;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		updateTreeAdd(node * 2, start, mid, left, right, val);
		updateTreeAdd(node * 2 + 1, mid + 1, end, left, right, val);
		segTree[node] = (segTree[node * 2] + segTree[node * 2 + 1]) % mod;
	}

	void updateTreeMultiply(int node, int start, int end, int left, int right, int val) {
		propagate(node, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			lazyTree[node].first = (lazyTree[node].first * val) % mod;
			lazyTree[node].second = (lazyTree[node].second * val) % mod;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		updateTreeMultiply(node * 2, start, mid, left, right, val);
		updateTreeMultiply(node * 2 + 1, mid + 1, end, left, right, val);
		segTree[node] = (segTree[node * 2] + segTree[node * 2 + 1]) % mod;
	}

	void updateTreeAssign(int node, int start, int end, int left, int right, int val) {
		propagate(node, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			segTree[node] = (ll)(end - start + 1) * val % mod;
			if (start != end) {
				lazyTree[node].first = 0;
				lazyTree[node].second = val;
			}
			return;
		}
		int mid = (start + end) / 2;
		updateTreeAssign(node * 2, start, mid, left, right, val);
		updateTreeAssign(node * 2 + 1, mid + 1, end, left, right, val);
		segTree[node] = (segTree[node * 2] + segTree[node * 2 + 1]) %mod;
	}

	void propagate(int node, int start, int end) {
		ll& m = lazyTree[node].first;
		ll& a = lazyTree[node].second;
		if (m == 1 && a == 0) return; //각 연산의 항등원이면 return

		segTree[node] = (segTree[node] * m) % mod;
		segTree[node] = (segTree[node] + a * (end - start + 1)) % mod;
		if (start != end) {
			for (int child : {node * 2, node * 2 + 1}) {
				lazyTree[child].first = (lazyTree[child].first * m) % mod;
				lazyTree[child].second = (lazyTree[child].second * m + a) % mod;
			}
		}
		m = 1; a = 0;
	}

	int queryTree(int node, int start, int end, int left, int right) {
		if (right < start || end < left) return 0;
		propagate(node, start, end);
		if (left <= start && end <= right) {
			return segTree[node] % mod;
		}
		int mid = (start + end) / 2;
		return ((queryTree(node * 2, start, mid, left, right)%mod) + (queryTree(node * 2 + 1, mid + 1, end, left, right)%mod))%mod;
	}

public:
	SegTree(vector<int>& data, int dSize) {
		_treeLastIdx = dSize - 1; //0~n-1
		segTree.resize(4 * dSize);
		lazyTree.assign(4 * dSize, { 1, 0 }); //초기화 주의
		build(data, 1, 0, _treeLastIdx);
	}

	void updateAdd(int node, int start, int end, int left, int right, int val) {
		updateTreeAdd(node, start, end, left - 1, right - 1, val);
	}
	void updateMultiply(int node, int start, int end, int left, int right, int val) {
		updateTreeMultiply(node, start, end, left - 1, right - 1, val);
	}
	void updateAssign(int node, int start, int end, int left, int right, int val) {
		updateTreeAssign(node, start, end, left - 1, right - 1, val);
	}
	int query(int node, int start, int end, int left, int right) {
		return queryTree(node, start, end, left-1, right - 1);
	}
};
void solve() {
    int n, m; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	SegTree segTree(arr, n);
	
	cin >> m;
	while (m--) {
		int cmd, left, right, val; cin >> cmd >> left >> right;
		if (cmd == 1) {
			cin >> val;
			segTree.updateAdd(1, 0, n - 1, left, right, val);
		}
		else if (cmd == 2) {
			cin >> val;
			segTree.updateMultiply(1, 0, n - 1, left, right, val);
		}
		else if (cmd == 3) {
			cin >> val;
			segTree.updateAssign(1, 0, n - 1, left, right, val);
		}
		else {
			cout << segTree.query(1, 0, n - 1, left, right) % mod << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}