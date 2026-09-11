#include <bits/stdc++.h>
using namespace std;

long long random_in_range(long long l, long long r) {
    static mt19937_64 engine(
        random_device{}() ^
        chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> dist(l, r);
    return dist(engine);
}

int main() {
    int n = random_in_range(1, 20);
    cout << n << '\n';
    vector<int> num(n + 1);
    for (int i = 1; i <= n; ++i) {
        num[i] = random_in_range(0, 1);
    }
    vector<int> cnt(2, 0);
    cout << "0 ";
    ++cnt[num[1]];
    for (int i = 2; i <= n; ++i) {
        ++cnt[num[i]];
        cout << cnt[num[i] ^ 1] << ' ';
    }
    cout << '\n';

    return 0;
}