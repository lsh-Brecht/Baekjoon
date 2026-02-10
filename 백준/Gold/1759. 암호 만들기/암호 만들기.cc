#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
int L, C;
vector<char> alphabets;
vector<char> password;

void bk(int idx, int count)
{
    if (count == L)
    {
        int vowels = 0;
        int consonants = 0;

        for (char c : password)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels++;
            else consonants++;
        }

        if (vowels >= 1 && consonants >= 2)
        {
            for (char c : password) cout << c;
            cout << "\n";
        }
        return;
    }

    for (int i = idx; i < C; i++)
    {
        password.push_back(alphabets[i]);
        bk(i + 1, count + 1);
        password.pop_back();              
    }
}

void solve()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        char temp;
        cin >> temp;
        alphabets.push_back(temp);
    }
    sort(alphabets.begin(), alphabets.end());
    bk(0, 0);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}