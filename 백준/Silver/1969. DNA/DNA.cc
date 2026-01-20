#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int arr[1002][5];
void solve() {
	//A C G T 순
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if(s[j]=='A')
				arr[j][0]++;
			else if (s[j] == 'C')
				arr[j][1]++;
			else if (s[j] == 'G')
				arr[j][2]++;
			else if (s[j] == 'T')
				arr[j][3]++;
		}
	}
	string ans = "";
	int sumv = 0;
	for (int j = 0; j < m; ++j) {
		int maxv = -1, maxIdx = -1, sum = 0;
		for (int i = 0; i < 4; ++i) {
			sum += arr[j][i];
			if (maxv < arr[j][i]) {
				maxv = arr[j][i];
				maxIdx = i;
			}
		}
		sum -= maxv;
		sumv += sum;
		switch (maxIdx) {
		case 0:
			ans += 'A';
			break;
		case 1:
			ans += 'C';
			break;
		case 2:
			ans += 'G';
			break;
		case 3:
			ans += 'T';
			break;
		}
	}
	cout << ans <<'\n'<< sumv;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}