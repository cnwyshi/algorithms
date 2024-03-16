#include <bits/stdc++.h>
using namespace std;
int b_f(int n, vector<vector<int>>& edge, int s, int t){
    vector<int> distance(n+1, INT_MAX/2);
    distance[s] = 0;
    for (int i = 0; i < n-1; i++) {
        for (vector<int>& v : edge) {
            int a = v[0], b = v[1];
            distance[b] = min(distance[b], distance[a] + 1);
        }
    }
    return distance[t] == INT_MAX/2 ? -1 : distance[t];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, s, t;
    cin >> n >> m;
    vector<vector<int>> edge;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        edge.push_back({a, b});
        edge.push_back({b, a});
    }
    cin >> s >> t;
    cout << b_f(n, edge, s, t) << endl;
    return 0;
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