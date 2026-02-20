#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
using ll = long long;

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> rus(N, -1);
    stack<int> s;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i)
    {
        while (!s.empty() && A[s.top()] < A[i])
        {
            rus[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < N; ++i)
    {
        cout << rus[i] << ' ';
    }
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}