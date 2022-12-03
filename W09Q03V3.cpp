#include<bits/stdc++.h>

using namespace std;
int n, k, f[100000][21][3];

// PSH
int dfs(vector<int>& a, int i, int k, int c) {
    if (i == n) {
        return 0;
    } else if (f[i][k][c])
        return f[i][k][c];
    int ans = 0;
    if ((c + 3 - a[i]) % 3 == 1) {
        ans = max(ans, dfs(a, i + 1, k, c) + 1);
    } else {
        ans = max(ans, dfs(a, i + 1, k, c));
        if (k > 0) {
            ans = max(ans, dfs(a, i + 1, k - 1, (a[i] + 1) % 3) + 1);
        }
    }
    return f[i][k][c] = ans;
}

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        a[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    cout << max(dfs(a, 0, k, 0), max(dfs(a, 0, k, 1), dfs(a, 0, k, 2))) << endl;
    return 0;
}