#include <bits/stdc++.h>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int i, int j, vector<vector<int>> grid, vector<vector<bool>> visited, int &ans, int n, int m, int ex, int ey) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1 || visited[i][j] == true) {
        return;
    }
//    cout << i << " " << j << " " << n << " " << m << endl;
    if (i == ex && j == ey) {
        ans++;
        return;
    }
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        dfs(i + dx[k], j + dy[k], grid, visited, ans, n, m, ex, ey);
    }
    visited[i][j] = false;
}

int main() {
    int n, m, t, ans = 0;
    cin >> n >> m >> t;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    if (sx == ex && sy == ey) {
        cout << 1 << endl;
        return 0;
    }
    sx--;
    sy--;
    ex--;
    ey--;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        grid[a][b] = 1;
    }
    dfs(sx, sy, grid, visited, ans, n, m, ex, ey);
    cout << ans << endl;
    return 0;
}
/*
 2 2 1

1 1 2 2

1 2

4 4 3
2 4 4 1
4 4
3 2
2 1
 */