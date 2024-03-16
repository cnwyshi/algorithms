#include <bits/stdc++.h>
using namespace std;

vector<int> b_f(int n, vector<vector<int>> &edge, int s) {
    vector<int> distance(n + 1, INT_MAX / 2);
    vector<int> parent(n + 1, -1);
    distance[s] = 0;
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (vector<int> &v: edge) {
            int a = v[0], b = v[1], w = v[2];
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                parent[b] = a;
                x = b;
            }
        }
    }
    if (x == -1) {
        return {};
    } else {
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }
        vector<int> path;
        for (int v = x; ; v = parent[v]) {
            path.push_back(v);
            if (v == x && path.size() > 1) {
                break;
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edge.push_back({a, b, w});
    }
    vector<int> path = b_f(n, edge, 1);
    if(path.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int v : path) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}