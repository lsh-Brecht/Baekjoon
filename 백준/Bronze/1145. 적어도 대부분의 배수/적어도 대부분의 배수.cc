#include <iostream>
#include <vector>
using namespace std;
void solve() {
	int arr[5];
	for(int i = 0; i < 5; i++)cin >> arr[i];
	int ans = 1;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (ans % arr[i] == 0)cnt++;
		}
		if(3 <= cnt){
			cout << ans;
			return;
		}
		ans++;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}