#include<bits/stdc++.h>

using namespace std;
const int maxn = 100005;
int n, k, a[maxn], f[maxn][25][5];

bool win(int a, int b) {
    return (a + 3 - b) % 3 == 1;
}

int dfs(int i, int k, int c, int s) {
    if (i == n - 1)
        return win(c, a[i]);
    if (f[i][k][c])
        return f[i][k][c];
    int ans = 0;
    if ((c + 3 - a[i]) % 3 == 1) {
        ans = max(ans, dfs(i + 1, k, c, s) + 1);
    } else {
        ans = max(ans, dfs(i + 1, k, c, s));
        if (k > 0) {
            ans = max(ans, dfs(i + 1, k - 1, (a[i] + 1) % 3, s) + 1);
        }
    }
    return f[i][k][c] = ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        a[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    cout << max(dfs(0, k, 0, 0), max(dfs(0, k, 1, 0), dfs(0, k, 2, 0))) << endl;
    return 0;
}