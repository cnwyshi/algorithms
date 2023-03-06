#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int n, k, f[100000][21][3];

// PSH
// http://www.usaco.org/index.php?page=viewproblem2&cpid=694
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

/*
100 13
S
H
H
P
H
S
P
H
P
S
S
S
H
H
P
S
H
P
H
P
P
P
P
H
H
S
P
P
P
P
H
S
P
S
H
P
P
S
S
H
P
S
S
S
H
H
P
P
P
S
H
H
P
S
H
P
P
H
P
S
H
P
P
P
P
S
P
H
S
H
H
H
S
H
P
S
S
S
S
S
S
S
S
H
P
S
H
H
S
P
H
H
H
P
H
H
S
S
P
S
*/