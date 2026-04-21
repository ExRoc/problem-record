#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 1000000 + 100;

// 找到小于等于 2026202620262026 的最大平衡数
// 形式：1111100000，0 与 1 的个数都是 25
void outputMaybe1(string s) {
    string ss = s.substr(1, s.length());
    sort(ss.begin(), ss.end());
    reverse(ss.begin(), ss.end());
    cout << ss << endl;
    // cout << "1125899873288192" << endl;
}

// 找到大于等于 2026202620262026 的最小平衡数
// 形式：1000001111，0 与 1 的个数都是 26
void outputMaybe2(string s) {
    string ss = "0" + s;
    sort(ss.begin(), ss.end());
    ss = "1" + ss.substr(0, ss.length() - 1);
    cout << ss << endl;
    // cout << "2251799847239679" << endl;
}

int main() {
    ios::sync_with_stdio(false);

    // 查询 s 的 0 1 个数
    // string s = "111001100101101001000001111011011000111011010001010";
    // int cnt[2] = {0, 0};
    // for (char ch : s) {
    //     ++cnt[ch - '0'];
    // }
    // for (int i = 0; i < 2; ++i) {
    //     cout << cnt[i] << endl;
    // }
    // outputMaybe1(s);
    // outputMaybe2(s);
    cout << "2251799847239679" << endl;

    return 0;
}
