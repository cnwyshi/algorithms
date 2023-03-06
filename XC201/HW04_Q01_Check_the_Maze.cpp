#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> maze, vector<vector<int>> &visited, int r, int c, int x, int y, int &count) {
    int n = maze.size();
    if (r < 0 || r >= n || c < 0 || c >= n || maze[r][c] == 1 || visited[r][c] == 1) {
        return;
    }
    if (r == x && c == y) {
        count++;
        return;
    }
    visited[r][c] = 1;
    dfs(maze, visited, r + 1, c, x, y, count);
    dfs(maze, visited, r - 1, c, x, y, count);
    dfs(maze, visited, r, c + 1, x, y, count);
    dfs(maze, visited, r, c - 1, x, y, count);
    visited[r][c] = 0;
}

int main() {
    int n, r, c, x, y, count = 0;
    cin >> n >> r >> c >> x >> y;
    vector<vector<int>> maze(n, vector<int>(n));
    vector<vector<int>> visited(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    if (maze[r][c] == 1 || maze[x][y] == 1) {
        return 0;
    }
    dfs(maze, visited, r, c, x, y, count);
    if (count >= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

