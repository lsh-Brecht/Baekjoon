#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
//lazy segmentTree를 일단 구조체로 이해
struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) : n(n) {
        //offset 계산 없이 4배로 잡아둠
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }
    void build(vector<ll>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, node * 2, start, mid);
        build(arr, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update_range(int node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range(node * 2, start, mid, l, r, val);
        update_range(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    ll query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(node * 2, start, mid, l, r) +
            query(node * 2 + 1, mid + 1, end, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];
    SegTree seg(N);
    seg.build(arr, 1, 1, N);
    for (int i = 0; i < M + K; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            ll d;
            cin >> b >> c >> d;
            seg.update_range(1, 1, N, b, c, d);
        }
        else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << seg.query(1, 1, N, b, c) << "\n";
        }
    }
}