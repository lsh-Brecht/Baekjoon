#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> temp(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> temp[i];
    }
    int cur = 0;
    for (int i = 0; i < K; ++i)
    {
        cur += temp[i];
    }
    int maxSum = cur;
    for (int i = K; i < N; ++i)
    {
        cur += temp[i];
        cur -= temp[i - K];
        if (cur > maxSum)
        {
            maxSum = cur;
        }
    }
    cout << maxSum;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}