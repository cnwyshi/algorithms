// Source: https://usaco.guide/general/io

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> sv(a, vector<int>(2));
    vector<vector<int>> sa(b, vector<int>(2));
    for (int i = 0; i < a; i++) {
        cin >> sv[i][0] >> sv[i][1];
        sv[i][0]--;
        sv[i][1]--;
    }
    for (int i = 0; i < b; i++) {
        cin >> sa[i][0] >> sa[i][1];
        sa[i][0]--;
        sa[i][1]--;
    }
//    cout << __LINE__ << endl;
    queue<vector<int>> q;
    vector<vector<int>> vis(n, vector<int>(m, -1));
    for (int i = 0; i < a; i++) {
        q.push({sv[i][0], sv[i][1]});
        vis[sv[i][0]][sv[i][1]] = 0;
    }
//    cout << __LINE__ << endl;
    while (!q.empty()) {
        vector<int> crt = q.front();
        q.pop();
        int cx = crt[0];
        int cy = crt[1];
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
//            cout << __LINE__ << endl;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
//                cout << __LINE__ << endl;
                q.push({nx, ny});
                vis[nx][ny] = vis[cx][cy] + 1;
            }
        }
    }
    for (int i = 0; i < b; i++) {
        cout << vis[sa[i][0]][sa[i][1]] << endl;
    }
}
