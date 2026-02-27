#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

//양수는 정렬해서 1을 제외하고 차례대로 둘씩 묶음
//음수는 정렬해서 차례대로 둘씩 묶음
//만일 가장 큰 음수가 하나 남는데 수열에 0이 있다면 0과 곱해줌.
vector<int> iPositiveVec;
vector<int> iNegativeVec;
void solve()
{
	int ans = 0;
	int n; cin >> n;
	bool bZeroExist = false;
	int oneCount = 0;
	for (int i = 0; i < n; ++i)
	{
		int iTemp;
		cin >> iTemp;
		if (iTemp == 1)
			++oneCount;
		else if (iTemp > 0)
			iPositiveVec.push_back(iTemp);
		else if (iTemp < 0)
			iNegativeVec.push_back(iTemp);
		else
			bZeroExist = true;
	}
	sort(iPositiveVec.begin(), iPositiveVec.end(), greater());
	sort(iNegativeVec.begin(), iNegativeVec.end(), less());
	int lenP = iPositiveVec.size();
	int lenN = iNegativeVec.size();
	for (int i = 0; i < (int)iPositiveVec.size(); i += 2)
	{
		if (i + 1 < iPositiveVec.size())
			ans += (long long)iPositiveVec[i] * iPositiveVec[i + 1];
		else
			ans += iPositiveVec[i];
	}
	ans += oneCount;
	for (int i = 0; i < lenN; i += 2)
	{
		if (i + 1 < lenN)
		{
			ans += iNegativeVec[i] * iNegativeVec[i + 1];
		}
		else
		{
			if (!bZeroExist)
			{
				ans += iNegativeVec[i];
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