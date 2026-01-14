#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

struct node {
	int num;
	node* leftchild;
	node* rightchilt;
	node() : num(0), leftchild(nullptr), rightchilt(nullptr) {}
};
node tree[10002]; //1~10000
int XcoordCnt = 0;
int nodeXcoord[10002];

int parent[10002];
int minXlevel[10002];
int maxXlevel[10002];
int maxDepth = 0;

void inorder(node* root, int dep) {
	if(root == nullptr) return;
	maxDepth = max(maxDepth, dep);
	inorder(root->leftchild, dep + 1);
	XcoordCnt++;
	minXlevel[dep] = min(minXlevel[dep], XcoordCnt);
	maxXlevel[dep] = max(maxXlevel[dep], XcoordCnt);
	inorder(root->rightchilt, dep + 1);
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i <= 10000; ++i) {
		minXlevel[i] = 1e9;
		maxXlevel[i] = -1;
	}
	for(int i=0;i<n;i++) {
		int a, b, c; cin >> a >> b >> c;
		tree[a].num = a;
		if (b != -1) {
			parent[b] = a;
			tree[a].leftchild = &tree[b];
		}
		if (c != -1) {
			parent[c] = a;
			tree[a].rightchilt = &tree[c];
		}
	}
	int rootIdx = 1;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == 0) {
			rootIdx = i;
			break;
		}
	}
	inorder(&tree[rootIdx], 1);

	int maxv = -1, maxLevel = -1;
	for (int i = 1; i <= maxDepth; ++i) {
		int cur = maxXlevel[i] - minXlevel[i] + 1;
		if (cur > maxv) {
			maxv = cur;
			maxLevel = i;
		}
	}
	cout << maxLevel << ' ' << maxv;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}