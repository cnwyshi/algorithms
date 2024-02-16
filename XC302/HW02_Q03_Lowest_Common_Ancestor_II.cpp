#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int u, int p, vector<int> &parent, vector<int> &depth) {
    for (int v: adj[u]) {
        if (v != p) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(adj, v, u, parent, depth);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> nodes(n + 1, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    vector<vector<int>> lca(q, vector<int>(2));
    for (vector<int> v: lca) {
        int a = v[0], b = v[1];
        vector<int> parent(n + 1), depth(n + 1);
        dfs(nodes, 1, 0, parent, depth);
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        int diff = depth[a] - depth[b];
        for (int i = 0; i < diff; i++) {
            a = parent[a];
        }
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        cout << a << endl;
    }
}
/*
Sample Input:
10 5
2 1
2 3
2 4
5 4
3 6
7 6
8 1
1 9
1 10
9 8
3 1
7 4
6 2
10 7

Sample Output:
1
1
2
2
1
*/