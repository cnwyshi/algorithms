#include <bits/stdc++.h>
using namespace std;
// You can move up, down, top-left, bottom-right for each one step.
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int n, m, lakes = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                int l = i, r = i, u = j, d = j, size = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                grid[i][j] = 0;
                lakes++;
                while (!q.empty()) {
                    int cx = q.front().first, cy = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cx + dx[k], ny = cy + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '#') {
                            q.push(make_pair(nx, ny));
                            grid[nx][ny] = 0;
                            l = min(l, nx);
                            r = max(r, nx);
                            u = min(u, ny);
                            d = max(d, ny);
                            size++;
//                            cout << nx << " " << ny << endl;
                        }
                    }
                }
                if((r-l+1) * (d-u+1) != size){
//                    cout << l << " " << r << " " << u << " " << d << " " << size << endl;
                    cout << "Bad placement." << endl;
                    return 0;
                }
            }
        }
    }
    cout << "There are " << lakes << " ships." << "\n";
}
/*
5 5
10011
10010
11011
01000
11010

i = 0; j = 0;
grid[i][j] = '1; q = [[0, 0]];
q.empty() = false;
cx = 0; cy = 0; q = [];
k = 0; nx = 1; ny = 0; lakes = 1; q = [[1, 0]]; grid[1][0] = 0;
k = 1; nx = -1; ny = 0;
k = 2; nx = 0; ny = 1; grid[0][1] = '0';
k = 3; nx = 0; ny = -1;
cx = 1; cy = 0;
*/