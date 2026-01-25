#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
//미리 범위 내에서 소수 값들을 전부 더하기 -> O(N^2)
//애초에 테스트케이스가 100개가 최대니까 상수는 무시 -> 입력받을 때마다 계산하면 O(N)
int ans[1000005];
vector<int> primes;
bool isNotPrime[1000001];

void primeProcessor() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i * i <= 1000001; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * i; j <= 1000001; j += i) {
            isNotPrime[j] = true;
        }
    }
    for (int i = 2; i <= 1000001; i++) {
        if (!isNotPrime[i]) primes.push_back(i);
    }
}
void sovle() {
    int k; cin >> k;
    int cnt = 0;
    for (int p : primes) {
        if (p > k / 2) break;
        if (!isNotPrime[k - p]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    primeProcessor();
    int t; cin >> t;
    while(t--) sovle();
	return 0;
}