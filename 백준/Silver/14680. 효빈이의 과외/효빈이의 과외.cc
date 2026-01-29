#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll A[51][51];
ll B[51][51];
ll C[51][51];

void solve()
{
    int N;
    cin >> N;
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];
    for (int idx = 1; idx < N; idx++)
    {
        int nr, nc;
        cin >> nr >> nc;

        for (int i = 0; i < nr; i++)
            for (int j = 0; j < nc; j++)
                cin >> B[i][j];

        if (c != nr)
        {
            cout << -1;
            return;
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < nc; j++)
                C[i][j] = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < nc; j++)
                A[i][j] = C[i][j];
        c = nc; //이전 열 벡터
    }

    ll ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ans = (ans + A[i][j]) % MOD;
    cout << ans % MOD;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}