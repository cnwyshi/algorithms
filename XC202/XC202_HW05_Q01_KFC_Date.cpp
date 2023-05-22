#include <bits/stdc++.h>

using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, minans = INT_MAX;
char mp[205][205];
int vis1[205][205], vis2[205][205];
struct node {
    int x, y, step;
};
int A, B, C, D;

void bfs(int x, int y, int vis[205][205]);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '@') {
                A = i;
                B = j;
            }
            if (mp[i][j] == '&') {
                C = i;
                D = j;
            }
        }
    }
    bfs(A, B, vis1);
    bfs(C, D, vis2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == 'F' && vis1[i][j] && vis2[i][j])
                minans = min(minans, vis1[i][j] + vis2[i][j]);
    if (minans == INT_MAX)
        cout << "Meeting cancelled";
    else
        cout << minans;
}

void bfs(int x, int y, int vis[205][205]) {
    queue<node> que;
    vis[x][y] = 1;
    que.push({x, y, 0});
    while (que.size()) {
        node hd = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int r = hd.x + dx[i];
            int c = hd.y + dy[i];
            int step = hd.step + 1;
            if (r < 1 || c < 1 || r > n || c > m || mp[r][c] == '#' || vis[r][c])
                continue;
            vis[r][c] = step;
            que.push({r, c, step});
        }
    }
}

