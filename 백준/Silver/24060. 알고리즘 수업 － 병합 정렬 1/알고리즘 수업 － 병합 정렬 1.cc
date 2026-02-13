#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

void merge_arr(ll p, ll q, ll r);
void merge_sort(ll p, ll r);

ll N, K;
ll cnt = 0;
ll ans = -1;
vector<ll> A;
vector<ll> tmp;

void merge_sort(ll p, ll r)
{
    if (p < r)
    {
        ll q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge_arr(p, q, r);
    }
}

void merge_arr(ll p, ll q, ll r)
{
    ll i = p, j = q + 1, t = 0;
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];

    while (j <= r)
        tmp[t++] = A[j++];
    i = p;
    t = 0;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == K)
        {
            ans = A[i - 1];
        }
    }
}

void solve()
{
    cin >> N >> K;
    A.resize(N);
    tmp.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    merge_sort(0, N - 1);

    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}