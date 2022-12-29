#include <iostream>
#include <vector>

using namespace std;
int f[100000][21][3];

// PSH
int dfs(vector<int>& a, int i, int k, int c, int s, int& ret) {
    if (i == a.size()) {
        printf("k = %d, c = %d, s = %d\n", k, c, s);
        ret = max(ret, s);
        return 0;
    } else if (f[i][k][c]) {
        return f[i][k][c];
    }
    int ans = 0;
    if ((c + 3 - a[i]) % 3 == 1) {
        ans = max(ans, dfs(a, i + 1, k, c, s + 1, ret) + 1);
    } else {
        ans = max(ans, dfs(a, i + 1, k, c, s, ret));
        if (k > 0) {
            ans = max(ans, dfs(a, i + 1, k - 1, (a[i] + 1) % 3, s + 1, ret) + 1);
        }
    }
    if (ans == 68) {
        printf("k = %d, c = %d, s = %d, f = %d\n", k, c, s, f[i][k][c]);
    }
    return f[i][k][c] = ans;
}

int main() {
    int n, k, ans = 0, ret = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        a[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    for (int j = 0; j < 3; j ++) {
        ans = max(ans, dfs(a, 0, k, j, 0, ret));
    }
    cout << ans << endl;
    cout << ret << endl;
    return 0;
}

/*
5 1
P
P
H
P
S
*/