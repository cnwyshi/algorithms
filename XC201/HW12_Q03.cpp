#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y, int dir, int turns, int &ans, vector<vector<int>> &maze, vector<vector<int>> &vis, int end_x, int end_y) {
    int n = maze.size();
    int m = maze[0].size();
    if(turns > ans){
        return;
    }
    cout << turns << " " << x << " " << y << " " << dir << endl;
    if (x == end_x - 1 && y == end_y - 1) {
        if (turns < ans) {
            ans = turns;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int new_x = x + dirs[i][0];
        int new_y = y + dirs[i][1];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && vis[new_x][new_y] == 0 && maze[new_x][new_y] == 0) {
            vis[new_x][new_y] = 1;
            if (i != dir) {
                dfs(new_x, new_y, i, turns + 1, ans, maze, vis, end_x, end_y);
            } else {
                dfs(new_x, new_y, i, turns, ans, maze, vis, end_x, end_y);
            }
            vis[new_x][new_y] = 0;
        }
    }
}
int main() {
    int start_x, start_y, end_x, end_y;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    cin >> start_x >> start_y >> end_x >> end_y;
    int ans = 123456789;
    dfs(start_x - 1, start_y - 1, 0, 0, ans, maze, vis, end_x, end_y);
    dfs(start_x - 1, start_y - 1, 1, 0, ans, maze, vis, end_x, end_y);
    dfs(start_x - 1, start_y - 1, 2, 0, ans, maze, vis, end_x, end_y);
    dfs(start_x - 1, start_y - 1, 3, 0, ans, maze, vis, end_x, end_y);
    cout << ans << endl;
}
/*
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 0 0 0 1 0 1
0 1 1 0 0 0 0
0 0 0 0 1 1 0
1 3 1 7

 1 2
 0 0
 0 0 0 1
*/
