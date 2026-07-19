#include <bits/stdc++.h>
using namespace std;

// 遍历 p 数组，第 i 位为中心的原数组的左端点下标为 (i - p[i]) /
// 2，最长回文子串长度为 p[i]
template <typename Container>
vector<int> manacher(const Container& s,
                     const typename Container::value_type& delim) {
    using T = typename Container::value_type;
    if (s.empty()) {
        return vector<int>{0};
    }

    vector<T> t;
    t.reserve(2 * s.size() + 1);
    for (int i = 0; i < (int)s.size(); ++i) {
        t.push_back(delim);
        t.push_back(s[i]);
    }
    t.push_back(delim);

    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        if (i < right) {
            int mirror = 2 * center - i;
            p[i] = min(right - i, p[mirror]);
        }
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
               t[i - p[i] - 1] == t[i + p[i] + 1]) {
            ++p[i];
        }
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> p = manacher(s, '#');
    int idx = 0, len = 0;
    for (int i = 0; i < (int)p.size(); ++i) {
        if (len < p[i]) {
            len = p[i];
            idx = (i - p[i]) / 2;
        }
    }
    cout << len << '\n' << s.substr(idx, len) << '\n';

    return 0;
}