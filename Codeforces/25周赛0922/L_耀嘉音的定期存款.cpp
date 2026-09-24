#include <bits/stdc++.h>
using namespace std;

pair<int, long long> getNext(int t) {
    long long add = 30;
    t = (t + add) % 7;
    while (t >= 5) {
        t = (t + 1) % 7;
        ++add;
    }
    return {t, add};
}

long long solve(int t, long long D) {
    if (D == 0) {
        return getNext(t).second;
    }
    int d = ((t - D) % 7 + 7) % 7;
    vector<pair<int, long long>> nexts;
    map<int, int> idx;
    nexts.push_back({d, 0});
    idx[d] = 0;
    int loopIdx;
    while (true) {
        pair<int, long long> next = getNext(d);
        next.second += nexts.back().second;
        if (idx.find(next.first) == idx.end()) {
            idx[next.first] = nexts.size();
            nexts.push_back(next);
            d = next.first;
            continue;
        }
        nexts.push_back(next);
        loopIdx = idx[next.first];
        break;
    }
    if (D > nexts.back().second) {
        D -= nexts[loopIdx].second;
        D %= nexts.back().second - nexts[loopIdx].second;
        D += nexts[loopIdx].second;
    }
    for (const pair<int, long long>& next : nexts) {
        if (next.second >= D) {
            return next.second - D;
        }
    }
    return INT_MAX;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> weekDays = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    string T;
    int N;
    cin >> T >> N;
    int t;
    for (int i = 0; i < 7; ++i) {
        if (T == weekDays[i]) {
            t = i;
            break;
        }
    }
    long long ans = INT_MAX;
    for (int i = 0; i < N; ++i) {
        long long D;
        cin >> D;
        ans = min(ans, solve(t, D));
    }
    cout << ans << '\n';

    return 0;
}