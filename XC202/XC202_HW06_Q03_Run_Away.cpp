#include <bits/stdc++.h>

using namespace std;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void solve() {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    vector<vector<vector<int>>> castle(a, vector<vector<int>>(b, vector<int>(c, 1)));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cin >> castle[i][j][k];
            }
        }
    }
    queue<vector<int>> q;
    map<vector<int>, int> vis;
    q.push({0, 0, 0});
    vis[{0, 0, 0}] = 0;
    while (!q.empty()) {
        vector<int> crt = q.front();
        q.pop();
        if (vis[crt] > t) {
            continue;
        }
        int x = crt[0], y = crt[1], z = crt[2];
        if (x == a - 1 && y == b - 1 && z == c - 1) {
            cout << vis[crt] << endl;
            return;
        }
        for (int h = 0; h < 6; h++) {
            int nx = x + dx[h], ny = y + dy[h], nz = z + dz[h];
            if (nx < a && nx >= 0 && ny < b && ny >= 0 && nz < c && nz >= 0 && vis.find({nx, ny, nz}) == vis.end() &&
                castle[nx][ny][nz] == 0) {
//                cout << nx << " " << ny << " " << nz << endl;
                q.push({nx, ny, nz});
                vis[{nx, ny, nz}] = vis[crt] + 1;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
/*
1

3 3 4 20

0 1 1 1

0 0 1 1

0 1 1 1

1 1 1 1

1 0 0 1

0 1 1 1

0 0 0 0

0 1 1 0

0 1 1 0
 */