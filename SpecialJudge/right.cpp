#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef struct Trie Trie;
vector<Trie*> arr;  // 存入AC自动机中所有的节点
struct Trie {
    Trie* links[26];
    Trie* fail;
    bool flag;             // 记录是否是字符串
    int postion, in, ans;  // postion 记录该字符串的位置 默认为 -1 , in
                           // 为该节点的入度 ans 为距离
    Trie() {
        memset(links, 0, sizeof links);
        flag = false;
        fail = 0, postion = -1, in = ans = 0;
    }
};
void Insert_string(string str, Trie* p, int postion) {
    for (auto vi : str) {
        int ch = vi - 'a';
        if (p->links[ch] == nullptr)
            p->links[ch] = new Trie();
        p = p->links[ch];
    }
    p->flag = true, p->postion = postion;
}
void Build_fail(Trie* root) {
    queue<struct Trie*> qu;
    qu.push(root);
    while (!qu.empty()) {
        auto first = qu.front();
        qu.pop();
        for (int i = 0; i < 26; ++i) {
            if (first->links[i]) {
                arr.push_back(first->links[i]);
                qu.push(first->links[i]);
                if (first == root)
                    first->links[i]->fail = root;
                else {
                    auto father = first->fail;
                    while (father) {
                        if (father->links[i]) {
                            first->links[i]->fail = father->links[i];
                            ++first->links[i]
                                  ->fail->in;  // fail 指向的节点入度 +1
                            break;
                        }
                        father = father->fail;
                    }
                    if (father == nullptr)
                        first->links[i]->fail = root;
                }
            }
        }
    }
}
void ac(string text, Trie* root) {
    auto p = root;
    for (auto vi : text) {
        int ch = vi - 'a';
        while (p && p->links[ch] == nullptr)
            p = p->fail;
        if (p == nullptr) {
            p = root;
            continue;
        }
        p = p->links[ch];
        ++p->ans;
    }
}
int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str, text;
    cin >> text;
    int n;
    cin >> n;
    Trie A;
    vector<int> postion(n + 1);
    unordered_map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        if (mp.count(str)) {
            postion[i] = -mp[str];
            continue;  // 如果该字符串之前插入了,那么 vector<i>
                       // 记录之前该字符串的位置
        }
        mp.insert({str, i});
        Insert_string(str, &A, i);
    }
    Build_fail(&A);
    // cin >> text;//文本串
    ac(text, &A);

    // 拓扑排序
    queue<Trie*> qu;
    for (auto vi : arr)  // 入度为 0 的节点入队
        if (!vi->in)
            qu.push(vi);
    while (!qu.empty()) {
        auto tmp = qu.front();
        qu.pop();
        tmp->fail->ans += tmp->ans;
        --tmp->fail->in;
        if (tmp->flag)
            postion[tmp->postion] += tmp->ans;
        if (!tmp->fail->in)
            qu.push(tmp->fail);
    }

    for (int i = 1; i <= n; ++i) {
        if (postion[i] < 0)  // 这个位置的字符串与 -postion[i] 位置的字符串相同
            cout << postion[-postion[i]] << endl;
        else
            cout << postion[i] << endl;
    }
    return 0;
}