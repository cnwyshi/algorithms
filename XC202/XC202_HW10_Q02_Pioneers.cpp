// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    map<vector<int>, int> vis;
    for (int i = 0; i < a; i++) {
        q.push(sv[i]);
        vis[sv[i]] = 0;
    }
//    cout << __LINE__ << endl;
    while (!q.empty()) {
        vector<int> crt = q.front();
        q.pop();
        int cx = crt[0];
        int cy = crt[1];
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            vector<int> nxt = {nx, ny};
//            cout << __LINE__ << endl;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis.find(nxt) == vis.end()) {
//                cout << __LINE__ << endl;
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
    }
    for (int i = 0; i < b; i++) {
        cout << vis[sa[i]] << endl;
    }
}
