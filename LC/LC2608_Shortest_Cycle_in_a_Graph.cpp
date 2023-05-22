#include <bits/stdc++.h>

using namespace std;

int findShortestCycle(int n, vector<vector<int>> edges) {
    vector<vector<int>> adj(n);
    cout << __LINE__ << endl;
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0], b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << __LINE__ << endl;

    int ans = n + 1;
    cout << __LINE__ << endl;

    for (int i = 0; i < n; i++) {
        cout << __LINE__ << endl;

        queue<int> q;
        q.push(i);
        vector<int> dist(n, -1);
        dist[i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: adj[u]) {
                if (dist[v] == -1) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                } else if (dist[v] >= dist[u]) {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
        // for(int v: dist){
        //     cout << v << " ";
        // }
        // cout << ans << endl;
    }
}

int main() {
    cout << findShortestCycle(4, {{0, 1},
                                  {0, 2}});
}