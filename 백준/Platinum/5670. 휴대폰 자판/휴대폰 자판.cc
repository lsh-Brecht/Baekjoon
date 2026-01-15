#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

struct Trie {
	Trie* child[26];
	int childCnt;
	bool isEndOfWord;
	Trie() : childCnt (0), isEndOfWord(false) {
		for (int i = 0; i < 26; ++i) child[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)
			if (child[i]) delete child[i];
	}

public:
	void link(string& other) {
		Trie* cur = this;
		for (auto& c : other) {
			int idx = c - 'a';
			if (nullptr == cur->child[idx]) {
				cur->child[idx] = new Trie();
				cur->childCnt++;
			}
			cur = cur->child[idx];
		}
		cur->isEndOfWord = true;
	}
};

ll dfs(Trie* node, int presses, bool isRoot) {
	ll ret = 0;
	if (node->isEndOfWord) ret += presses;
	for (int i = 0; i < 26; ++i) {
		if (node->child[i]) {
			//child가 있는데 단어의 마지막이라면 눌러야 함
			//app, apple
			if (isRoot || node->childCnt > 1 || node->isEndOfWord)
				ret += dfs(node->child[i], presses + 1, false);
			else
				ret += dfs(node->child[i], presses, false);
		}
	}
	return ret;
}

void solve() {
	int n;
	while (true) {
		if (!(cin >> n)) break;
		Trie* root = new Trie();
		vector<string> words(n);
		for (int i = 0; i < n; ++i) {
			cin >> words[i];
			root->link(words[i]);
		}
		ll totalPress = dfs(root, 0, true);
		cout << fixed << setprecision(2);
		cout << (double)totalPress / n << '\n';
		delete root;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}