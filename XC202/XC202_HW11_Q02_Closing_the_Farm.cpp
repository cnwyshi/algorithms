#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n + 1);
    vector<int> closed(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> closed[i];
    }
    for (int t = 0; t < n; t++) {
        queue<int> q;
        set<int> vis;
        q.push(closed[n - 1]);
        vis.insert(closed[n - 1]);
        while (!q.empty()) {
            int crt = q.front();
            q.pop();
            for (int j: graph[crt]) {
                int nt = j;
                if (vis.find(nt) == vis.end()) {
                    q.push(nt);
                    vis.insert(nt);
                }
            }
        }
        for (int i: vis) {
            // cout<< i << " ";
        }
        // cout<< endl;
        cout << (vis.size() == n - t ? "YES" : "NO") << endl;
        for (int i = 1; i <= n; i++) {
            // cout<< i << ": ";
            for (int j: graph[i]) {
                // cout<< j << " ";
            }
            // cout<< endl;
        }
        graph[closed[t]].clear();
        for (int i = 0; i < n + 1; i++) {
            graph[i].erase(closed[t]);
        }
        for (int i = 1; i <= n; i++) {
            // cout<< i << ": ";
            for (int j: graph[i]) {
                // cout<< j << " ";
            }
            // cout<< endl;
        }
    }
    return 0;
}
/*
4 3
1 2
2 3
3 4
3
4
1
2

YES
NO
YES
YES
*/