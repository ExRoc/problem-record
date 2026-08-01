#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    set<vector<int>> ABs;
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        if (A > B) {
            swap(A, B);
        }
        ABs.insert({A, B});
    }
    M = ABs.size();
    if (M == 1) {
        cout << (N - 1) * 2 - 1 << '\n';
        return 0;
    }
    vector<int> cnt(N + 1, 0);
    for (const vector<int>& AB : ABs) {
        ++cnt[AB[0]];
        ++cnt[AB[1]];
    }
    int maxCntNum = 1;
    int ansBase = 0;
    for (int i = 1; i <= N; ++i) {
        if (cnt[i] == M) {
            ansBase = N - 1;
        }
        if (cnt[i] > cnt[maxCntNum]) {
            maxCntNum = i;
        }
    }
    set<vector<int>> ansTmp;
    if (ansBase == 0) {
        vector<int> p1(2, 0), p2(2, 0);
        for (const vector<int>& AB : ABs) {
            if (AB[0] != maxCntNum && AB[1] != maxCntNum) {
                p2 = AB;
            }
        }
        int sameCnt = 2;
        for (const vector<int>& AB : ABs) {
            int sameCntTmp = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (AB[i] == p2[j]) {
                        ++sameCntTmp;
                    }
                }
            }
            if (sameCntTmp < sameCnt) {
                sameCnt = sameCntTmp;
                p1 = AB;
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (p1[i] != p2[j]) {
                    vector<int> tmp = {p1[i], p2[j]};
                    sort(tmp.begin(), tmp.end());
                    ansTmp.insert(tmp);
                }
            }
        }
    } else {
        set<int> st;
        for (const vector<int>& AB : ABs) {
            for (int j = 0; j < 2; ++j) {
                st.insert(AB[j]);
            }
        }
        st.erase(maxCntNum);
        set<int>::iterator it = st.begin();
        vector<int> tmp = {*it};
        ++it;
        tmp.push_back(*it);
        ansTmp.insert(tmp);
    }
    for (const vector<int>& AB : ABs) {
        vector<vector<int>> erases;
        for (const vector<int>& tmp : ansTmp) {
            bool flag = false;
            for (int ii = 0; ii < 2; ++ii) {
                for (int jj = 0; jj < 2; ++jj) {
                    if (AB[ii] == tmp[jj]) {
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                erases.push_back(tmp);
            }
        }
        for (const vector<int>& e : erases) {
            ansTmp.erase(e);
        }
    }
    cout << ansTmp.size() + ansBase << '\n';

    return 0;
}