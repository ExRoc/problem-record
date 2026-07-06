#include <bits/stdc++.h>
using namespace std;

const int maxn = 150000 + 100;
const int llog2 = 20;
vector<int> baseSort[maxn];
int nxt[maxn][llog2];
// rnk[i][j] 初始下标为 i，长度为 2^j 的字符串的排名
int rnk[maxn][llog2];
// sa[i] 排名为 i 的字符串的初始下标
int sa[maxn];

class Log2Table {
   public:
    static int Get(int n) {
        static vector<int> table = {0, 0};
        if (n >= static_cast<int>(table.size())) {
            int old = table.size();
            table.resize(n + 1);
            for (int i = max(2, old); i <= n; ++i) {
                table[i] = table[i / 2] + 1;
            }
        }
        return table[n];
    }
};

void sortSa(int j, int N) {
    int maxRnk = 0;
    for (int i = 0; i < N; ++i) {
        int rnkTmp = rnk[nxt[sa[i]][j]][j];
        maxRnk = max(maxRnk, rnkTmp);
        baseSort[rnkTmp].push_back(sa[i]);
    }
    int saIdx = 0;
    for (int i = 0; i <= maxRnk; ++i) {
        for (int x : baseSort[i]) {
            sa[saIdx++] = x;
        }
        baseSort[i].clear();
    }
    maxRnk = 0;
    for (int i = 0; i < N; ++i) {
        int rnkTmp = rnk[sa[i]][j];
        maxRnk = max(maxRnk, rnkTmp);
        baseSort[rnkTmp].push_back(sa[i]);
    }
    saIdx = 0;
    for (int i = 0; i <= maxRnk; ++i) {
        for (int x : baseSort[i]) {
            sa[saIdx++] = x;
        }
        baseSort[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int N;
        cin >> N;
        string D;
        cin >> D;
        int log2 = Log2Table::Get(N) + 1;
        set<char> st(D.begin(), D.end());
        for (int i = 0; i < N; ++i) {
            nxt[i][0] = (1LL * i * i + 1) % N;
            sa[i] = i;
            int rankTmp = 0;
            for (set<char>::iterator it = st.begin(); it != st.end(); ++it) {
                if (*it == D[i]) {
                    rnk[i][0] = rankTmp;
                }
                ++rankTmp;
            }
        }
        for (int j = 1; j <= log2; ++j) {
            sortSa(j - 1, N);
            for (int i = 0; i < N; ++i) {
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            }
            rnk[sa[0]][j] = 0;
            for (int i = 1; i < N; ++i) {
                int cmpRes = 0;
                int a = sa[i - 1];
                int b = sa[i];
                if (rnk[a][j - 1] != rnk[b][j - 1]) {
                    cmpRes = (rnk[a][j - 1] < rnk[b][j - 1]);
                } else {
                    cmpRes =
                        rnk[nxt[a][j - 1]][j - 1] < rnk[nxt[b][j - 1]][j - 1];
                }
                rnk[sa[i]][j] = rnk[sa[i - 1]][j] + cmpRes;
            }
        }
        string ans;
        int idx = sa[N - 1];
        for (int i = 0; i < N; ++i) {
            ans.push_back(D[idx]);
            idx = (1LL * idx * idx + 1) % N;
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}