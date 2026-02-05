#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
using ll = long long;

class Word
{
public:
    string text;
    int count;
    int len;
    //람다나 compare 함수보다 연산자 오버로딩이 더 편함
    bool operator<(const Word& other)
    {
        if (count != other.count)
        {
            return count > other.count;
        }
        if (len != other.len)
        {
            return len > other.len;
        }
        return text < other.text;
	}
};

void solve()
{
	int n, m; cin >> n >> m;
    map<string, int> freq;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s.length() >= m)
        {
            freq[s]++;
        }
    }

    vector<Word> vWord;
    for (auto& [text, count] : freq)
    {
        int len = text.length();
        vWord.push_back({ text, count, len });
    }
    sort(vWord.begin(), vWord.end());
    for (auto& w : vWord)
    {
        cout << w.text << '\n';
    }
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}