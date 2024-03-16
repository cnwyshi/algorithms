#include<bits/stdc++.h>
using namespace std;
long long INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, a, b, c;
    cin >> n >> m;
    vector<vector<vector<long long>>> adj (n+1);
    while(m--){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
//  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
    pq.push({0, 1});
    vector<long long> dist(n+1, INF);
    dist[1] = 0;
    vector<long long> visited (n+1);
    while(!pq.empty()){
        long long crt = pq.top()[1];
        pq.pop();
        if(visited[crt]){
            continue;
        }
        visited[crt] = 1;
        for(vector<long long> v : adj[crt]){
            long long node = v[0];
            long long weight = v[1];
            if(!visited[node] && weight < dist[node]){
                dist[node] = weight;
                pq.push({dist[node], node});
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i < dist.size(); i++){
        ans += dist[i];
    }
    cout << ans << endl;
}
/*
5 7
1 2 17
1 4 5
1 5 23
2 3 30
2 4 10
3 4 24
3 5 7

45


[2, 17], [4, 5], [5, 23]
[1, 17], [3, 30]*/