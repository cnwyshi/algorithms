#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> maze, vector<vector<int>> &visited, int r, int c, int &count, int &ans, int steps, int n,
         int m) {
    if (r < 0 || r >= n || c < 0 || c >= m || maze[r][c] == '#' || visited[r][c] == 1) {
        return;
    }
    if (maze[r][c] != '*') {
        steps += maze[r][c] - '0';
    }
    if (r == n - 1 && c == m - 1) {
        if (steps > ans) {
            ans = steps;
        }
        steps = 0;
        count++;
        return;
    }
    visited[r][c] = 1;
    dfs(maze, visited, r + 1, c, count, ans, steps, n, m);
    dfs(maze, visited, r - 1, c, count, ans, steps, n, m);
    dfs(maze, visited, r, c + 1, count, ans, steps, n, m);
    dfs(maze, visited, r, c - 1, count, ans, steps, n, m);
    visited[r][c] = 0;
}

int main() {
    int n, m, count = 0;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    int ans = 0;
    dfs(maze, visited, 0, 0, count, ans, 0, n, m);
    if (count < 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans;
    return 0;
}
/*
6 3
**3
171
9*6
069
794
#44

3+1+7+1+9+6+6+9+7+9+4+4+4
  */

