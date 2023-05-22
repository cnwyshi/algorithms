#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t, m, n, sx, sy, d, ans = 0;
    int D[] = {0, 1, 0, -1, 0};
    cin >> t;
    while (t-- > 0) {
        cin >> m >> n >> sx >> sy >> d;
        vector<vector<int>> maze(m, vector<int>(n));
        for (int i = max(0, sx - d); i <= sx + d; i++) {
            for (int j = max(0, sy - d); j <= sy + d; j++) {
                if (abs(i - sx) + abs(j - sy) <= d && i < m && j < n) {
                    maze[i][j] = 1;
                }
            }
        }
        queue<pair<int, int>> bfs;
        vector<vector<bool>> visited;
        bfs.push({0, 0});
        visited[0][0] = true;
        for (ans = 0; !bfs.empty(); ans++) {
            for (int c = bfs.size(); c > 0; bfs.pop(), c--) {
                pair<int, int> &p = bfs.front();
                int x = p.first, y = p.second;
                for (int i = 0; i < 4; i++) {
                    int r = x + D[i], c = y + D[i + 1];
                    if (r == m - 1 && c == n - 1) {

                    }
                    if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                        bfs.push({r, c});
                        visited[r][c] = true;
                    }
                }
            }
        }

    }
    return 0;
}

/*
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1


*/