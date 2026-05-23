#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    map<char, int> mp;
    vector<string> str = {"abc", "def",  "ghi", "jkl",
                          "mno", "pqrs", "tuv", "wxyz"};
    for (int i = 0; i < 8; ++i) {
        for (char ch : str[i]) {
            mp[ch] = i + 2;
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        cout << mp[S[0]];
    }
    cout << '\n';

    return 0;
}