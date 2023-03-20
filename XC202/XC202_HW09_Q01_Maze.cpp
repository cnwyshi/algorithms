#include <bits/stdc++.h>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int n, m, t, ans = 0;
    cin >> n >> m >> t;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;
    queue<pair<int, int>> q;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        grid[a][b] = 1;
    }
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        if (cx == ex && cy == ey) {
            ans++;
            cout << __LINE__ << " " << cx << " " << cy << " " << ans << endl;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
             cout << nx << " " << ny << " " << i << " " << n << " " << m << endl;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                 cout << grid[nx][ny] << " " << visited[nx][ny]<< endl;
            }
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != 1 && visited[nx][ny] != true) {
                q.push(make_pair(nx, ny));
                 cout << nx << " " << ny << " " << cx << " " << cy << endl;
                visited[nx][ny] = true;
            }
        }
    }
    cout << ans << "\n";
}
/*
 2 2 1

1 1 2 2

1 2

4 4 3
2 4 4 1
4 4
3 2
2 1
 */