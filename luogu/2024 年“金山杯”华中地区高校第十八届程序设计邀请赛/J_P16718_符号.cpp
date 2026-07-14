#include <bits/stdc++.h>
using namespace std;

struct Block {
    static int blockSize;
    int idx, blockId, l, r;

    Block() {}

    Block(int idx, int l, int r)
        : idx(idx), blockId(l / blockSize), l(l), r(r) {}

    bool operator<(const Block& other) const {
        return blockId == other.blockId ? r < other.r : blockId < other.blockId;
    }
};

int Block::blockSize = 1;

struct Node {
    char ch;
    int len;

    Node() {}

    Node(char ch, int len) : ch(ch), len(len) {}

    bool operator<(const Node& other) const { return false; }
};

ostream& operator<<(ostream& out, const Node& node) {
    out << "ch = " << node.ch << " len = " << node.len;
    return out;
}

void pushBackR(int r, const string& S, deque<Node>& que, long long& ans) {
    if (S[r] == '<') {
        if (que.empty() || que.back().ch == '>') {
            que.push_back(Node('<', 1));
            ++ans;
        } else {
            ++que.back().len;
            ans += que.back().len;
        }
    } else {
        if (que.empty()) {
            que.push_back(Node('>', 1));
            ++ans;
        } else {
            if (que.back().ch == '<') {
                que.push_back(Node('>', 1));
            } else {
                if ((int)que.size() == 1) {
                    ++que.back().len;
                    ans += que.back().len;
                } else {
                    Node node = que.back();
                    que.pop_back();
                    ++node.len;
                    if (node.len > que.back().len) {
                        ans += node.len;
                    } else {
                        ans += node.len - 1;
                    }
                    que.push_back(node);
                }
            }
        }
    }
}

void pushFrontL(int l, const string& S, deque<Node>& que, long long& ans) {
    if (S[l] == '>') {
        if (que.empty() || que.front().ch == '<') {
            que.push_front(Node('>', 1));
            ++ans;
        } else {
            ++que.front().len;
            ans += que.front().len;
        }
    } else {
        if (que.empty()) {
            que.push_front(Node('<', 1));
            ++ans;
        } else {
            if (que.front().ch == '>') {
                que.push_front(Node('<', 1));
            } else {
                if ((int)que.size() == 1) {
                    ++que.front().len;
                    ans += que.front().len;
                } else {
                    Node node = que.front();
                    que.pop_front();
                    ++node.len;
                    if (node.len > que.front().len) {
                        ans += node.len;
                    } else {
                        ans += node.len - 1;
                    }
                    que.push_front(node);
                }
            }
        }
    }
}

void popBackR(int r, const string& S, deque<Node>& que, long long& ans) {
    if (que.back().ch == '<') {
        ans -= que.back().len;
        --que.back().len;
        if (que.back().len == 0) {
            que.pop_back();
        }
    } else {
        if ((int)que.size() == 1) {
            ans -= que.back().len;
            --que.back().len;
        } else {
            Node node = que.back();
            que.pop_back();
            if (node.len > que.back().len) {
                ans -= node.len;
            } else {
                ans -= node.len - 1;
            }
            --node.len;
            if (node.len != 0) {
                que.push_back(node);
            }
        }
    }
}

void popFrontL(int l, const string& S, deque<Node>& que, long long& ans) {
    if (que.front().ch == '>') {
        ans -= que.front().len;
        --que.front().len;
        if (que.front().len == 0) {
            que.pop_front();
        }
    } else {
        if ((int)que.size() == 1) {
            ans -= que.front().len;
            --que.front().len;
        } else {
            Node node = que.front();
            que.pop_front();
            if (node.len > que.front().len) {
                ans -= node.len;
            } else {
                ans -= node.len - 1;
            }
            --node.len;
            if (node.len != 0) {
                que.push_front(node);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Block::blockSize = sqrt(N);
    string S;
    cin >> S;
    S = ' ' + S;
    vector<Block> blocks;
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        blocks.push_back(Block(i, L, R));
    }
    sort(blocks.begin(), blocks.end());
    int l = 1;
    int r = 0;
    vector<long long> ans(M);
    deque<Node> que;
    long long ansTmp = 0;
    for (int i = 0; i < M; ++i) {
        if (blocks[i].l > blocks[i].r) {
            ans[blocks[i].idx] = 0;
            continue;
        }
        while (r < blocks[i].r) {
            ++r;
            pushBackR(r, S, que, ansTmp);
        }
        while (l > blocks[i].l) {
            --l;
            pushFrontL(l, S, que, ansTmp);
        }
        while (r > blocks[i].r) {
            popBackR(r, S, que, ansTmp);
            --r;
        }
        while (l < blocks[i].l) {
            popFrontL(l, S, que, ansTmp);
            ++l;
        }
        ans[blocks[i].idx] = ansTmp;
    }
    for (int i = 0; i < M; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}