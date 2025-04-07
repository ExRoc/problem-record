#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (ls | 1)
using namespace std;
const int N = 2e6 + 10, M = 5e2 + 10, V = 63, p = 13331, mod = 998244353,
          md = 998244353, INF = 1e18;
int n, m, k, a[N], b[N], c[N], d[N], in[N], to[N], mp[N];
char s[N], t[N];
namespace Fast_IO {
static char buf[1000000], *paa = buf, *pd = buf, out[10000000];
int length = 0;
#define getchar()                                                              \
    paa == pd && (pd = (paa = buf) + fread(buf, 1, 1000000, stdin), paa == pd) \
        ? EOF                                                                  \
        : *paa++
inline int read() {
    int x(0), t(1);
    char fc(getchar());
    while (!isdigit(fc)) {
        if (fc == '-')
            t = -1;
        fc = getchar();
    }
    while (isdigit(fc))
        x = (x << 1) + (x << 3) + (fc ^ 48), fc = getchar();
    return x * t;
}
inline void flush() {
    fwrite(out, 1, length, stdout);
    length = 0;
}
inline void put(char c) {
    if (length == 9999999)
        flush();
    out[length++] = c;
}
inline void put(string s) {
    for (char c : s)
        put(c);
}
inline void print(int x) {
    if (x < 0)
        put('-'), x = -x;
    if (x > 9)
        print(x / 10);
    put(x % 10 + '0');
}
inline bool chk(char c) {
    return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||
             c >= '0' && c <= '9');
}
inline bool ck(char c) {
    return c != '\n' && c != '\r' && c != -1 && c != ' ';
}
inline void rd(char s[], int& n) {
    s[++n] = getchar();
    while (chk(s[n]))
        s[n] = getchar();
    while (ck(s[n]))
        s[++n] = getchar();
    n--;
}
}  // namespace Fast_IO
using namespace Fast_IO;
inline void topo() {
    queue<int> q;
    for (int i = 'a'; i <= 'z'; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        mp[u] = 1;
        int v = to[u];
        if (mp[v] == 0)
            in[v] = 0, q.push(v);
    }
}
inline void dfs(int u) {
    mp[u] = 1;
    int v = to[u];
    if (mp[v] == 0)
        dfs(v);
}
inline void solve() {
    read();
    rd(s, n);
    n = 0;
    rd(t, n);
    set<char> st;
    for (int i = 1; i <= n; i++) {
        if (to[s[i]] == 0 || to[s[i]] == t[i])
            to[s[i]] = t[i];
        else
            return put("-1\n");
        st.emplace(t[i]);
    }
    if (st.size() == 26) {
        for (int i = 1; i <= n; i++)
            if (s[i] != t[i])
                return put("-1\n");
        return put("0\n");
    }
    int ans = 0;
    memset(to, 0, sizeof to);
    for (int i = 1; i <= n; i++)
        if (to[s[i]] == 0 && s[i] != t[i]) {
            to[s[i]] = t[i];
            in[t[i]]++;
            ans++;
        }
    topo();
    for (int i = 'a'; i <= 'z'; ++i)
        if (mp[i] == 0)
            ans++, dfs(i);
    print(ans);
    put('\n');
}
signed main() {
    int T = 1;
    // T=read();
    while (T--)
        solve();
genshin:;
    flush();
    return 0;
}