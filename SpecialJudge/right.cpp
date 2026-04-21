#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    vector<int> preL(N + 1, 0), preQ(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        preL[i] = preL[i - 1] + (s[i - 1] == 'L' ? 1 : 0);
        preQ[i] = preQ[i - 1] + (s[i - 1] == 'Q' ? 1 : 0);
    }

    int totalL = preL[N], totalQ = preQ[N];
    long long base = 0;
    // 计算确定的 L 与确定的 Q 形成的对数
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            base +=
                totalQ - preQ[i + 1];  // i 位置后面（严格大于i）的确定 Q 数量
        }
    }

    vector<int> posQmark;  // 存放 '?' 的位置（0-based）
    for (int i = 0; i < N; ++i) {
        if (s[i] == '?') {
            posQmark.push_back(i);
        }
    }

    int M = posQmark.size();
    vector<long long> gainL(M, 0), gainQ(M, 0);
    for (int i = 0; i < M; ++i) {
        int idx = posQmark[i];
        // 如果将该 '?' 变为 L，贡献：后面确定 Q 的个数
        gainL[i] = totalQ - preQ[idx + 1];
        // 如果变为 Q，贡献：前面确定 L 的个数
        gainQ[i] = preL[idx];  // idx 位置之前（严格小于idx）的确定 L 数量
    }

    // 前缀和便于快速计算区间和
    vector<long long> sumL(M + 1, 0), sumQ(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        sumL[i + 1] = sumL[i] + gainL[i];
        sumQ[i + 1] = sumQ[i] + gainQ[i];
    }

    long long ans = 0;
    for (int t = 0; t <= M; ++t) {
        // 前 t 个 '?' 变成 L，后 M-t 个变成 Q
        long long cur = base;
        cur += sumL[t] - sumL[0];  // 前 t 个的 gainL
        cur += sumQ[M] - sumQ[t];  // 后 M-t 个的 gainQ
        cur += 1LL * t * (M - t);  // 变为 L 和变为 Q 的 '?' 之间的对数
        if (cur > ans) ans = cur;
    }

    cout << ans << '\n';
    return 0;
}