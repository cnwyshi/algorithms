#include<bits/stdc++.h>

using namespace std;
long long INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, a, b, c;
    cin >> n >> m;
    vector<vector<vector<long long>>> adj(n + 1);
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<long long> visited(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, i});
        vector<long long> dist(n + 1, INF);
        dist[i] = 0;
        while (!pq.empty()) {
            long long crt = pq.top()[1];
            pq.pop();
            if (visited[crt]) {
                continue;
            }
            visited[crt] = 1;
            for (vector<long long> v: adj[crt]) {
                long long node = v[0];
                long long weight = v[1];
                if (!visited[node] && weight < dist[node]) {
                    dist[node] = weight;
                    pq.push({dist[node], node});
                }
            }
        }
        for (int j = 1; j < dist.size(); j++) {
//            cout << i << " " << dist[j] << endl;
            if (dist[j] != INF) {
                ans += dist[j];
            }
        }
    }
    cout << ans << endl;
}
/*
7  9
1  2  1
1  3  2
2  3  3
4  5  1
4  7  3
5  6  2
6  7  4
4  6  5
5  7  8

9

1---(1)---2
|        /
(2)    (3)
|      /
3----+


 */