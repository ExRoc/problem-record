#include <cstdio>
using namespace std;

typedef long long LL;
const int maxn = 3000000 + 100;
int cnt, a, b;
LL ans;
LL prime[maxn], phi[maxn];
bool visit[maxn];

void Prime(int n) {
    cnt = 0;
    phi[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!visit[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] < n; ++j) {
            int k = i * prime[j];
            visit[k] = true;
            if (i % prime[j] == 0) {
                phi[k] = phi[i] * prime[j];
                break;
            } else {
                phi[k] = phi[i] * (prime[j] - 1);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        phi[i] += phi[i - 1];
    }
}

int main() {
    Prime(maxn - 50);
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%I64d\n", phi[b] - phi[a - 1]);
    }

    return 0;
}
