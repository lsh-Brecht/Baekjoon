#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <deque>
using namespace std;
using ll = long long;
//이분 매칭. 아마 한번 보면 안 잊을듯
int N, M;
vector<int> adj[1001];//직원의 매칭 가능한 업무
int work[1001];//인덱스와 매칭된 직원 번호
bool visited[1001];
bool dfs(int x) {
    for (int t : adj[x]) {
        if (visited[t]) continue;
        visited[t] = true;
        if (!work[t] || dfs(work[t])) {
            work[t] = x;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int canjob; cin >> canjob;
        for (int j = 0; j < canjob; ++j) {
            int task; cin >> task;
            adj[i].push_back(task);
        }
    }
    int rus = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j)
            visited[j] = false;
        if (dfs(i)) ++rus;
    }
    cout << rus;
    return 0;
}