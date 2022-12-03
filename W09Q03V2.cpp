#include<bits/stdc++.h>

using namespace std;
const int maxn = 100005;
int n, k, a[maxn], f[maxn][25][5];

bool check(int a, int b) {
    return (a + 3 - b) % 3 == 1;
}

int dfs(int i, int k, int c) {
    if (k == -1)
        return 0;
    if (i == 1)
        return check(c, a[i]);
    if (f[i][k][c])
        return f[i][k][c];
    int ret = 0;
    for (int j = 0; j < 3; ++j) {
        ret = max(ret, dfs(i - 1, k - (j != c), j) + (k - (j != c) >= 0 ? check(j, a[i]) : 0));
    }
    return f[i][k][c] = ret;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n + 1; i ++) {
        char c;
        cin >> c;
        a[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    cout << max(dfs(n, k, 0), max(dfs(n, k, 1), dfs(n, k, 2))) << endl;
    return 0;
}