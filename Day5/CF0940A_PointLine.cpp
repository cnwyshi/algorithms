#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 105
#define MAX(a, b) a>b?a:b
using namespace std;
int n, d, mx;
int pre[MAXN];

int main() {
    mx = -1;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    sort(pre, pre + n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (pre[j] - pre[i] <= d) {
                mx = MAX(mx, j - i + 1);
            }
        }
    }
    printf("%d\n", n - mx);
    return 0;
}

// https://codeforces.com/problemset/problem/940/A
// https://cloud.tencent.com/developer/article/1382230