#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
//어떤 메모리가 액세스될 지 미리 알고 있는 LRU알고리즘? OPT
vector<int> arr;

void solve()
{
    int n, k;
    cin >> n >> k;

    arr.resize(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> arr[i];
    }
    vector<int> multitap;
    int cnt = 0;
    for (int i = 0; i < k; ++i)
    {
        int cur = arr[i];
        bool is_on = false;
        for (int i : multitap)
        {
            if (i == cur)
            {
                is_on = true;
                break;
            }
        }
        if (is_on) continue;
        if (multitap.size() < n)
        {
            multitap.push_back(cur);
            continue;
        }
        int replaceTarget = -1;
        int LNU = -1;
        for (int j = 0; j < multitap.size(); ++j)
        {
            int plugged = multitap[j];
            int next_use = -1;
            for (int m = i + 1; m < k; ++m)
            {
                if (arr[m] == plugged)
                {
                    next_use = m;
                    break;
                }
            }
            if (next_use == -1)
            {
                replaceTarget = j;
                break;
            }
            if (next_use > LNU)
            {
                LNU = next_use;
                replaceTarget = j;
            }
        }
        multitap[replaceTarget] = cur;
        cnt++;
    }
    cout << cnt;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}