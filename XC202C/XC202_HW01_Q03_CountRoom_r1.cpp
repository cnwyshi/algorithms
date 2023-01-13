#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string>& maze, int i, int j) {
    int m = maze.size(), n = maze[0].size();
    if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == '.') {
        maze[i][j] = '#';
        dfs(maze, i + 1, j);
        dfs(maze, i - 1, j);
        dfs(maze, i, j + 1);
        dfs(maze, i, j - 1);
    }
}

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    vector<string> maze(m);
    for (int i = 0; i < m; i ++) {
        cin >> maze[i];
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (maze[i][j] == '.') {
                dfs(maze, i, j);
                ans ++;
            }
        }
    }
    cout << ans << endl;
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
 */