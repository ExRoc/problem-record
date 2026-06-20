#include <bits/stdc++.h>
using namespace std;

bool desc(int a, int b) { return a > b; }

long long solveMax(int n, int x, const vector<int>& a) {
    set<int> st;
    for (int aa : a) {
        int aTmp = aa - x;
        if (aa < aTmp) {
            swap(aa, aTmp);
        }
        if (aa > 0 && st.find(aa) == st.end()) {
            st.insert(aa);
        } else if (aTmp > 0) {
            st.insert(aTmp);
        }
    }
    long long ret = 0;
    for (int xx : st) {
        ret += xx;
    }
    return ret;
}

long long solveMin(int n, int x, const vector<int>& a) {
    set<int> st;
    for (int aa : a) {
        int aTmp = aa - x;
        if (aa > aTmp) {
            swap(aa, aTmp);
        }
        if (aa < 0 && st.find(aa) == st.end()) {
            st.insert(aa);
        } else if (aTmp < 0) {
            st.insert(aTmp);
        }
    }
    long long ret = 0;
    for (int xx : st) {
        ret += xx;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> aAsc = a;
    vector<int> aDesc = a;
    sort(aAsc.begin(), aAsc.end());
    sort(aDesc.begin(), aDesc.end(), desc);
    long long maxAns = solveMax(n, x, aDesc);
    long long minAns = solveMin(n, x, aAsc);
    cout << minAns << ' ' << maxAns << '\n';

    return 0;
}