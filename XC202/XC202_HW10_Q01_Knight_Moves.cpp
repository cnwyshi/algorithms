// Source: https://usaco.guide/general/io

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
//You can move up, down, top-left, bottom-right for each one step.
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, -1, 1, 2, -2, 2, -2};

int main() {
    int n, sx, sy, ex, ey;
    cin >> n >> sx >> sy >> ex >> ey;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n));
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    int steps = 0;
    for (; !q.empty(); steps++) {
        // cout << steps << " " << q.size() << endl;
        for (int s = q.size(); s > 0; s--) {
            int cx = q.front().first, cy = q.front().second;
            // cout << cx << " " << cy << endl;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];
                // cout << nx << " " << ny << endl;
                // cout << n << " " << m << endl;
                // cout << sx << " " << sy << endl;
                // cout << (nx >= 0 && ny >= 0 && nx < n && ny < m) << " " << (!visited[nx][ny]) << endl;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    if (nx == ex && ny == ey) {
                        cout << steps + 1 << endl;
                    }
                    // cout << nx << " " << ny << endl;
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
/*
3 3 1 1

0    3    2
3    -1   1
2    1    4
*/