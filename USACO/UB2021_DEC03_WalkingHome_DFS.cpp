#include <bits/stdc++.h>

using namespace std;

void dfs(vector<string>& matrix, int i, int j, int k, int d, int& ans) {
    int n = matrix.size();
    if (i >= n || j >= n || k < 0 || matrix[i][j] == 'H') {
        return;
    } else if (i == n - 1 && j == n - 1) {
        ans ++;
        return;
    }
    if (d == 0) {
        dfs(matrix, i, j + 1, k, 0, ans);
        dfs(matrix, i + 1, j, k - 1, 1, ans);
    } else {
        dfs(matrix, i, j + 1, k - 1, 0, ans);
        dfs(matrix, i + 1, j, k, 1, ans);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> matrix(n);
        for (int i = 0; i < n; i++) {
            cin >> matrix[i];
        }
        int ans = 0;
        dfs(matrix, 0, 1, k, 0, ans);   // right
        dfs(matrix, 1, 0, k, 1, ans);   // down
        cout << ans << endl;
    }
}

/*
7
3 1
...
...
...
3 2
...
...
...
3 3
...
...
...
3 3
...
.H.
...
3 2
.HH
HHH
HH.
3 3
.H.
H..
...
4 3
...H
.H..
....
H...


 */