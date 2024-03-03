#include <bits/stdc++.h>
using namespace std;
bool b_f(int n, vector<vector<int>>& edge, int s, int t){
    vector<int> distance(n+1, INT_MAX/2);
    distance[s] = 0;
    for (int i = 0; i < n-1; i++) {
        for (vector<int>& v : edge) {
            int a = v[0], b = v[1], w = v[2];
            distance[b] = min(distance[b], distance[a] + w);
        }
    }
    vector<int> copy = distance;
    for (vector<int>& v : edge) {
        int a = v[0], b = v[1], w = v[2];
        distance[b] = min(distance[b], distance[a] + w);
    }
    if(copy != distance){
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        vector<vector<int>> edge;
        int n, m, a, b, w;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> w;
            edge.push_back({a, b, w});
        }
        cout << (b_f(n, edge, 1, n) == true ? "YES" : "NO") << endl;
    }
}
/*
4 4
1 2
1 3
2 4
3 4
1 4


1 2 3 4
0 1 1



         1
        / \
        2 3
        \ /
         4
 */