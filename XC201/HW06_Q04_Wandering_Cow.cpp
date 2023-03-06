#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<vector<char>> &maze, int r, int c, int &count, int steps, int r2, int c2, int t) {
    int n = maze.size(), m = maze[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m || maze[r][c] == '*') {
        return;
    }
    // cout << r << " " << c << " " << steps << endl;
    if (steps + abs(r2 - r) + abs(c2 - c) > t) {
        return;
    }
    if (r == r2 && c == c2 && steps == t) {
        count++;
        return;
    }
    // minimum: abs(r2-r) + abs(c2-c)
    dfs(maze, r + 1, c, count, steps + 1, r2, c2, t);
    dfs(maze, r - 1, c, count, steps + 1, r2, c2, t);
    dfs(maze, r, c + 1, count, steps + 1, r2, c2, t);
    dfs(maze, r, c - 1, count, steps + 1, r2, c2, t);
}

int main() {
    int n, m, t;
    int count = 0;
    cin >> n >> m >> t;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    dfs(maze, r1 - 1, c1 - 1, count, 0, r2 - 1, c2 - 1, t);
    cout << count;
    return 0;
}
/*
3 4 3
.*.*
.*.*
.*.*
2 3 3 3


4 5 6
...*.
...*.
.....
.....
1 3 1 5




20 20 15
..*.......**...*....
................**..
....*............*..
....**............*.
..*.................
.....*..............
.............*.**...
........*..*......**
.............*.*.*..
.....*........*.....
.*..*....*..........
*................*..
***.................
.........*....*.....
.......**...........
...........**.....*.
..*.*...............
....*......*........
....................
........*.......*...
18 11 18 10


0/0 0/1 0/2 0/3
1/0 1/1 1/2 1/3
2/0 2/1 2/2 2/3 
current: r,c 
destination: r2,c2
minimum: abs(r2-r) + abs(c2-c)
*/
  