#include <bits/stdc++.h>
using namespace std;

template <int K, typename KeyT, typename ValT, int (*id)(KeyT)>
class Trie {
   public:
    Trie() { nodes_.emplace_back(); }

    void clear() {
        nodes_.clear();
        nodes_.emplace_back();
    }

    template <typename InputIt>
    void insert(InputIt first, InputIt last, const ValT& v = ValT{}) {
        int pos = 0;
        for (auto it = first; it != last; ++it) {
            int idx = id(*it);
            int& nxt = nodes_[pos].next[idx];
            if (nxt == 0) {
                nxt = static_cast<int>(nodes_.size());
                pos = nxt;
                nodes_.emplace_back();
            } else {
                pos = nxt;
            }
            nodes_[pos].cnt += v;
        }
        nodes_[pos].endCnt += v;
    }

    template <typename InputIt>
    ValT query(InputIt first, InputIt last) const {
        int pos = 0;
        for (auto it = first; it != last; ++it) {
            int idx = id(*it);
            int nxt = nodes_[pos].next[idx];
            if (nxt == 0) {
                return ValT{};
            }
            pos = nxt;
        }
        return nodes_[pos].endCnt;
    }

    template <typename InputIt>
    bool contains(InputIt first, InputIt last) const {
        int pos = 0;
        for (auto it = first; it != last; ++it) {
            int idx = id(*it);
            int nxt = nodes_[pos].next[idx];
            if (nxt == 0) {
                return false;
            }
            pos = nxt;
            if (nodes_[pos].cnt == 0) {
                return false;
            }
        }
        return true;
    }

   private:
    struct Node {
        int next[K];
        ValT endCnt, cnt;

        Node() : endCnt(ValT{}), cnt(ValT{}) { memset(next, 0, sizeof(next)); }
    };

    vector<Node> nodes_;
};

int id(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    }
    return ch - '0' + 26;
}

template <int K, typename KeyT, typename ValT, int (*id)(const KeyT&)>
class Trie {
   public:
    Trie() { nodes_.emplace_back(); }

    void clear() {
        nodes_.clear();
        nodes_.emplace_back();
    }

    template <typename InputIt>
    void insert(InputIt first, InputIt last, const ValT& v = ValT{}) {
        int pos = 0;
        for (auto it = first; it != last; ++it) {
            int idx = id(*it);
            int& nxt = nodes_[pos].next[idx];
            if (nxt == 0) {
                nxt = static_cast<int>(nodes_.size());
                pos = nxt;
                nodes_.emplace_back();
            } else {
                pos = nxt;
            }
        }
        nodes_[pos].val = v;
    }

    template <typename InputIt>
    ValT query(InputIt first, InputIt last) const {
        int pos = 0;
        for (auto it = first; it != last; ++it) {
            int idx = id(*it);
            int nxt = nodes_[pos].next[idx];
            if (nxt == 0) {
                return ValT{};
            }
            pos = nxt;
        }
        return nodes_[pos].val;
    }

    template <typename InputIt>
    bool contains(InputIt first, InputIt last) const {
        int pos = 0;
        for (auto it = first; it != last; ++it) {
            int idx = id(*it);
            int nxt = nodes_[pos].next[idx];
            if (nxt == 0) {
                return false;
            }
            pos = nxt;
        }
        return true;
    }

   private:
    struct Node {
        int next[K];
        ValT val;

        Node() : val(ValT{}) { memset(next, 0, sizeof(next)); }
    };

    vector<Node> nodes_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Trie<36, char, int, id> trie;
    while (n--) {
        int op;
        string str;
        cin >> op >> str;
        if (op == 1) {
            trie.insert(str.begin(), str.end(), 1);
            cout << trie.query(str.begin(), str.end()) << '\n';
        } else if (op == 2) {
            if (trie.contains(str.begin(), str.end())) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            trie.insert(str.begin(), str.end(),
                        -trie.query(str.begin(), str.end()));
        }
    }

    return 0;
}