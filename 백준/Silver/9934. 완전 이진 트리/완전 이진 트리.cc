#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
//배열로 만드는 게 더 편하지만

int inorder[1025];
struct Node
{
    int num;
    Node* left;
    Node* right;
	Node(int val) : num(val), left(nullptr), right(nullptr) {}
};

Node* dfs(int l, int r)
{
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    Node* root = new Node(inorder[mid]);
    root->left = dfs(l, mid - 1);
    root->right = dfs(mid + 1, r);
    return root;
}

void bfsPrint(Node* root)
{
    int pow2 = 1;
    int num = 0;
    queue<Node*> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node* cur = qu.front(); qu.pop();
        cout << cur->num;
        ++num;
        if (num != pow2)
        {
            cout << ' ';
        }
        if (num == pow2)
        {
            cout << '\n';
            num = 0;
			pow2 *= 2;
        }
        if (cur->left)
        {
            qu.push(cur->left);
        }
        if (cur->right)
        {
            qu.push(cur->right);
        }
    }
}

void solve()
{
    int n; cin >> n;
    int len = (1<<n) - 1;
    for (int i = 0; i < len; ++i)
    {
        cin >> inorder[i];
    }
    Node* root = dfs(0, len - 1);
    bfsPrint(root);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}