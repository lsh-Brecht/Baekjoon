#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;
using ll = long long;
int n, A[4000], B[4000], C[4000], D[4000], S[16000000];
int k;
ll ans;
void solve()
{
	cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    unordered_map<int, int> sumAB;
    sumAB.reserve(n * n / 2);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sumAB[A[i] + B[j]]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int target = -(C[i] + D[j]);
            auto it = sumAB.find(target);
            if (it != sumAB.end())
            {
                ans += it->second;
            }
        }
    }
    cout << ans;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}