#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	int cnt = 0;
	unordered_map<string, int> umap;
	for (int i = 0; i < n; ++i)
	{
		string name, clothe_type;
		cin >> name >> clothe_type;
		umap[clothe_type]++;
		if (umap.find(clothe_type) == umap.end())
		{
			cnt++;
		}
	}
	ll result = 1;
	for (auto& p : umap)
	{
		result *= (p.second + 1);
	}

	result -= 1;
	cout << result << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}