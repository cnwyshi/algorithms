#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &maze, int r, int c, int &ans, int steps, int n, int m, int past) {
//    cout << r << " " << c << " " << ans << " " << steps << " " << past << endl;
    if (r < 0 || r >= n || c < 0 || c >= m || maze[r][c] >= past) {
        return;
    }
//    if(maze[r-1][c] > maze[r][c] && maze[r+1][c] > maze[r][c] && maze[r][c-1] > maze[r][c] && maze[r][c+1] > maze[r][c]){
//        if(steps > ans){
//            ans = steps;
//            steps = 0;
//        }
//    }
    ans = max(ans, steps);
    past = maze[r][c];
    dfs(maze, r + 1, c, ans, steps + 1, n, m, past);
    dfs(maze, r - 1, c, ans, steps + 1, n, m, past);
    dfs(maze, r, c + 1, ans, steps + 1, n, m, past);
    dfs(maze, r, c - 1, ans, steps + 1, n, m, past);
}

int main() {
    int n, m, count = 0, ans = 0;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(maze, i, j, ans, 1, n, m, maze[i][j] + 1);
        }
    }
    cout << ans;
    return 0;
}
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/