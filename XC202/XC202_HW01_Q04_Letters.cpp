#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(vector<string> &maze, int i, int j, vector<bool> visited, int length, int &ans) {
    ans = max(ans, length);
    int m = maze.size(), n = maze[0].size();
    if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] != '#' && !visited[maze[i][j]]) {
        char c = maze[i][j];
        // printf("i = %d, j = %d, c = %c, length = %d\n", i, j, c, length);
        maze[i][j] = '#';
        visited[c] = true;
        dfs(maze, i + 1, j, visited, length + 1, ans);
        dfs(maze, i - 1, j, visited, length + 1, ans);
        dfs(maze, i, j + 1, visited, length + 1, ans);
        dfs(maze, i, j - 1, visited, length + 1, ans);
        maze[i][j] = c;
        visited[c] = false;
    }
}

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    vector<string> maze(m);
    for (int i = 0; i < m; i++) {
        cin >> maze[i];
    }
    vector<bool> visited(128);
    dfs(maze, 0, 0, visited, 0, ans);
//    for (int i = 0; i < m; i ++) {
//        for (int j = 0; j < n; j ++) {
//            dfs(maze, i, j, visited, 0, ans);
//        }
//    }
    cout << ans << endl;
}

/*
3 6
HFDFFB
AJHGDH
DGAGEH

FDEGAHJ
*/