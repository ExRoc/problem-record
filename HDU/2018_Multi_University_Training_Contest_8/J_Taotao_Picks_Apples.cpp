#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
struct Node {
    int q, idx;
    Node() {}
    Node(int q, int idx) : q(q), idx(idx) {}
};

int T, n, m, p, q, last, top;
int num[maxn], pre[maxn], sta[maxn], ans[maxn], preMax[maxn];
vector<Node> vct[maxn];

int getAns(int idx, int x) {
    int low = -1;
    int high = top;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (sta[mid] > x) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return pre[idx - 1] + 1 + low + 1;
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        last = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            if (num[i] > last) {
                last = num[i];
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = pre[i - 1];
            }
            vct[i].clear();
            preMax[i] = max(preMax[i - 1], num[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &p, &q);
            vct[p].push_back(Node(q, i));
        }
        top = 0;
        for (int i = n; i >= 1; --i) {
            int len = vct[i].size();
            for (int j = 0; j < len; ++j) {
                q = vct[i][j].q;
                int idx = vct[i][j].idx;
                if (q <= preMax[i - 1]) {
                    ans[idx] = getAns(i, preMax[i - 1]) - 1;
                } else {
                    ans[idx] = getAns(i, vct[i][j].q);
                }
            }
            while (top != 0 && sta[top - 1] <= num[i]) {
                --top;
            }
            sta[top++] = num[i];
        }
        for (int i = 0; i < m; ++i) {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
