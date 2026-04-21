#include <bits/stdc++.h>
using namespace std;
struct Node {
    long long a, b;
    double t;

    Node() {}

    Node(long long a, long long b, double t) : a(a), b(b), t(t) {}

    bool operator<(const Node& other) const { return t < other.t; }
};

long long getCnt(long long a, long long b, double t) {
    long long low = (b - a * t) / (t * b) - 1;
    long long high = low + 5;
    long long mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (b <= (a + mid * b) * t) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return max(high, 0LL);
}

bool judge(double mid, int n, int m, vector<long long>& a,
           vector<long long>& b) {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += getCnt(a[i], b[i], mid);
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(n);
    double high = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        high = max(high, (double)b[i] / a[i]);
    }
    double low = 0;
    double mid;
    while (high - low > 1e-10) {
        mid = (high + low) / 2;
        if (judge(mid, n, m, a, b)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    for (int i = 0; i < n; ++i) {
        long long cnt = getCnt(a[i], b[i], high);
        a[i] += cnt * b[i];
        m -= cnt;
    }
    priority_queue<Node> que;
    for (int i = 0; i < n; ++i) {
        que.push(Node(a[i], b[i], (double)b[i] / a[i]));
    }
    while (m != 0) {
        --m;
        Node tmp = que.top();
        que.pop();
        tmp.a += tmp.b;
        tmp.t = (double)tmp.b / tmp.a;
        que.push(tmp);
    }
    const long long MOD = 998244353;
    long long ans = 1;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        ans = ans * tmp.a % MOD;
    }
    cout << ans << '\n';

    return 0;
}
