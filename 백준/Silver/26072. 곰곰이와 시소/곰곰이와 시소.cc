#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

//문제유형 확인
vector<double> x;
vector<double> w;
void solve()
{
    int N;
    double L;
    cin >> N >> L;
    x.resize(N);
    w.resize(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    for (int i = 0; i < N; i++) cin >> w[i];
    double low = 0.0;
    double high = L;
    for (int i = 0; i < 200; i++)
    {
        double mid = (low + high) / 2.0;
        double WL = 0.0;
        double WR = 0.0;

        for (int j = 0; j < N; j++)
        {
            if (x[j] < mid)
            {
                WL += w[j] * (mid - x[j]);
            }
            else
            {
                WR += w[j] * (x[j] - mid);
            }
        }
        if (WL > WR)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << fixed << setprecision(11) << low;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}