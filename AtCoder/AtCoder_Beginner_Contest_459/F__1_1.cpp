#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len;
    long long sum;

    Node() {}

    Node(int len, long long sum) : len(len), sum(sum) {}

    void merge(const Node& other) {
        len += other.len;
        sum += other.sum;
    }

    bool operator<(const Node& other) const {
        return sum * other.len < other.sum * len;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        stack<Node> sta;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            A[i] = A[i] - i + N;
            Node node(1, A[i]);
            while (!sta.empty() && node < sta.top()) {
                node.merge(sta.top());
                sta.pop();
            }
            sta.push(node);
        }
        int idx = N;
        long long ans = 0;
        long long tmp = 0;
        while (!sta.empty()) {
            Node node = sta.top();
            sta.pop();
            idx -= node.len;
            for (int i = 0; i < node.len; ++i) {
                int target = (node.sum + i) / node.len;
                if (target < A[idx + i]) {
                    tmp += A[idx + i] - target;
                } else {
                    tmp -= target - A[idx + i];
                }
                ans += tmp;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}