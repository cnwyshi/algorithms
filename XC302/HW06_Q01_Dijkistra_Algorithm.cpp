#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n, vector<vector<pair<int, int>>> adj) {
    vector<int> dist(n+1, INT_MAX/2);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int crt = pq.top().second;
        int crt_dist = pq.top().first;
        pq.pop();
        if(crt_dist != dist[crt])
            continue;
        for (auto neighbor : adj[crt]) {
            if(crt_dist + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = crt_dist + neighbor.second;
                pq.push({dist[neighbor.first], neighbor.first});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<int> ans = dijkstra(n, adj);
    for(int i = 1; i <= n; i++){
        if(ans[i] != INT_MAX/2){
            cout << ans[i] << " ";
        }
        else{
            cout << "inf" << " ";
        }
    }
    cout << endl;
    return 0;
}