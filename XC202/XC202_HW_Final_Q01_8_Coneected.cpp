#include <bits/stdc++.h>

using namespace std;
// You can move up, down, top-left, bottom-right for each one step.
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};

int main() {
    int n, m, lakes = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'W') {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                lakes++;
                while (!q.empty()) {
                    int cx = q.front().first, cy = q.front().second;
                    q.pop();
                    for (int k = 0; k < 8; k++) {
                        int nx = cx + dx[k], ny = cy + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && nx >= 0 && ny >= 0 && grid[nx][ny] == 'W') {
                            q.push(make_pair(nx, ny));
                            grid[nx][ny] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << lakes << "\n";
}
/*
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/