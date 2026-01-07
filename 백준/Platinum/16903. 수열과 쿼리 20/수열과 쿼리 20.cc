#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
//문자열에만 사용되는 줄 알았던 trie에 bit를 넣는 방법

class BinaryTrie {
private:
    struct Node {
        int children[2];
        int cnt;
        Node()
        {
            children[0] = children[1] = -1;
            cnt = 0;
        }
    };
    
    vector<Node> trie;
    int MAX_BIT;

public:
    BinaryTrie() {
        trie.emplace_back();
        MAX_BIT = 30;
    }

    void insert(int x) {
        int curr = 0;
        for (int i = MAX_BIT; i >= 0; --i) {
            int bit = (x >> i) & 1; //i번째 bit
            if (trie[curr].children[bit] == -1) {
                trie[curr].children[bit] = trie.size();
                trie.emplace_back();
            }
            curr = trie[curr].children[bit];
            trie[curr].cnt++;
        }
    }

    void remove(int x) {
        int curr = 0;
        for (int i = MAX_BIT; i >= 0; --i) {
            int bit = (x >> i) & 1;
            curr = trie[curr].children[bit];
            trie[curr].cnt--;
        }
    }

    int getMaxXorval(int x) {
        int curr = 0;
        int ret = 0;
        for (int i = MAX_BIT; i >= 0; --i) {
            int bit = (x >> i) & 1;
            int target = 1 ^ bit;
            if (trie[curr].children[target] != -1 && trie[trie[curr].children[target]].cnt > 0) {
                ret |= (1 << i);
                curr = trie[curr].children[target];
            }
            else {
                //반대 bit가 없다면 같은 bit로
                curr = trie[curr].children[bit];
            }
        }
        return ret;
    }
};

void solve() {
    int q; cin >> q;
    BinaryTrie bt;
    bt.insert(0);
    while (q--) {
		int cmd; cin >> cmd;
        if(cmd == 1) {
            int x; cin >> x;
            bt.insert(x);
        }
        else if(cmd == 2) {
            int x; cin >> x;
            bt.remove(x);
        }
        else {
            int x; cin >> x;
            cout << bt.getMaxXorval(x) << '\n';
		}
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	solve();
	return 0;
}