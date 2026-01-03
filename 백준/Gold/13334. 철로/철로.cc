#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Worker {
public:
    int start;
    int end;
    bool operator<(const Worker& other) const {
        return end < other.end;
    }
};
void solve() {
    int n; cin >> n;
    vector<Worker> people(n);
    for (int i = 0; i < n; i++) {
        int h, o;
        cin >> h >> o;
        if (h > o) swap(h, o);
        people[i] = { h, o };
    }
    int d; cin >> d;
    sort(people.begin(), people.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int max_count = 0;
    for (auto& p : people) {
        int start = p.start;
        int end = p.end;
        pq.push(start);
        while (!pq.empty() && pq.top() < end - d) {
            pq.pop();
        }
        if (end - start <= d) {
            max_count = max(max_count, (int)pq.size());
        }
    }
    cout << max_count;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
	return 0;
}