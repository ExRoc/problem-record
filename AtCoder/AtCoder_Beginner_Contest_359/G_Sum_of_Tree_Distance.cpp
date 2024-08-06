#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
struct Node {
    LL cnt, dis, depth;
    Node() {
        cnt = 0;
        dis = 0;
        depth = 0;
    }

    Node(LL cnt, LL dis, LL depth) : cnt(cnt), dis(dis), depth(depth) {}

    void update(LL d) {
        LL dd = depth - d;
        dis += dd * cnt;
        depth = d;
    }

    void merge(Node& other) {
        assert(depth == other.depth);
        cnt += other.cnt;
        dis += other.dis;
    }
};

int n, u, v;
LL ans;
int num[maxn];
vector<int> G[maxn];
map<int, Node> mp[maxn];

void dfs(int root, int fa, int depth) {
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root, depth + 1);
        if (mp[root].size() < mp[pos].size()) {
            swap(mp[root], mp[pos]);
        }
        for (auto it : mp[pos]) {
            Node& rootNode = mp[root][it.first];
            rootNode.update(depth);
            Node& posNode = it.second;
            posNode.update(depth);
            ans += rootNode.cnt * posNode.dis + posNode.cnt * rootNode.dis;
            rootNode.merge(posNode);
        }
    }
    Node rootNode = Node(1, 0, depth);
    Node& posNode = mp[root][num[root]];
    posNode.update(depth);
    ans += posNode.dis;
    posNode.merge(rootNode);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    dfs(1, 1, 0);
    cout << ans << endl;

    return 0;
}
