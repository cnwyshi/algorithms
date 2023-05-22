#include <bits/stdc++.h>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++){
//            cout << grid[i][j] << " ";
//        }
//        cout << endl;
//    }
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    int steps = 0;
    for (; !q.empty(); steps++) {
        for (int z = q.size(); z > 0; z--) {
            int cx = q.front().first, cy = q.front().second;
            if (cx == ex && cy == ey) {
                cout << steps << "\n";
                return 0;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];
//                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
//                    cout << cx << " " << cy << " " << nx << " " << ny << grid[nx][ny] << " " << visited[nx][ny] << endl;
//                }
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && visited[nx][ny] != true) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
    cout << -1 << "\n";
}
/*
6 7
#S#####
#...#.#
#.#.#.#
#.#...G
#...#.#
#######*/