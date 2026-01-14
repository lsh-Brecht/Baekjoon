#include <iostream>
#include <vector>
using namespace std;
int N, K, cnt = 0;
vector<int> arr[51];
void dfs(int curr) {
    if (curr == K) return;
    int childCount = 0;
    for (int child : arr[curr]) {
        if (child != K) {
            dfs(child);
            childCount++;
        }
    }
    if (childCount == 0) cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int temp, root = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == -1) {
            root = i;
        } else
            arr[temp].push_back(i); //temp에서 i를 갈 수 있다
    }
    cin >> K;
    if (K == root) {
        cout << 0 << "\n";
    } else {
        dfs(root);
        cout << cnt << "\n";
    }
    return 0;
}