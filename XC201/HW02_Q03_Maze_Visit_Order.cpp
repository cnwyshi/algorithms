#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void flood(vector<vector<int>> &maze, int r, int c, int &index, vector<vector<int>> &order) {
    int m = maze.size(), n = maze[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || maze[r][c] == 1) {
        return;
    }
    maze[r][c] = 1;
    order[r][c] = index++;
    flood(maze, r - 1, c, index, order);
    flood(maze, r, c - 1, index, order);
    flood(maze, r, c + 1, index, order);
    flood(maze, r + 1, c, index, order);
    // cout << r << " " << c << " " << n <<endl;
}

int main() {
    int n = 0, m = 0, index = 1;
    cin >> m >> n;
    vector<vector<int>> maze(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> order(m, vector<int>(n));
    flood(maze, 0, 0, index, order);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << order[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
3 4
0 0 0 0
1 0 1 0
0 0 0 0
 */