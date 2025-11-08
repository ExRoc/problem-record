#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2000000 + 100;
int T, n;
char str1[maxn], str2[maxn];
int Next[maxn];

void get_next(char* s) {
    Next[1] = 0;
    int j = 0;
    for (int i = 2; s[i]; ++i) {
        while (j > 0 && s[i] != s[j + 1]) {
            j = Next[j];
        }
        if (s[i] == s[j + 1]) {
            ++j;
        }
        Next[i] = j;
    }
}

int KMP(char* s1, char* s2) {
    int j = 0, ret = 0;
    for (int i = 1; s1[i]; ++i) {
        while (j > 0 && s1[i] != s2[j + 1]) {
            j = Next[j];
        }
        if (s1[i] == s2[j + 1]) {
            ++j;
        }
        if (s2[j + 1] == '\0') {
            return i - n;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);

    // 题意：输入 T, 然后 T 组数据，每组数据两个字符串 A, B
    // 字符串仅包含 0 1
    // 每次操作可以将字符串 A 的第一个字符移除，放到 A 的最后一个字符后面
    // 问最少需要移动多少次，能使 A 与 B 字符串完全相等
    // 如果完全无法相等，就输出 -1

    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", str1 + 1, str2 + 1);
        n = strlen(str1 + 1);
        for (int i = 1; i <= n; ++i) {
            str1[i + n] = str1[i];
        }
        str1[n * 2 + 1] = '\0';
        get_next(str2);
        cout << KMP(str1, str2) << endl;
    }

    return 0;
}
