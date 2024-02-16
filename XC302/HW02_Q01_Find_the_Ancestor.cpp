#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int u, int p, vector<vector<int>> &ancestor) {
    ancestor[u][0] = p;
    for (int i = 1; (1 << i) < adj.size(); i++) {
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != p) {
            dfs(adj, v, u, ancestor);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    int h = log(n + 1) / log(2), x, y, k;
    vector<vector<int>> graph(n + 1), ancestor(n + 1, vector<int>(h));
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(graph, 1, 0, ancestor);
    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        for (int j = h; j >= 0; j--) {
            if (k & (1 << j)) {
                x = ancestor[x][j];
            }
        }
        cout << x << '\n';
    }
}
/*
Sample input 1：
10 5
1 2
1 3
4 2
3 5
6 4
4 7
4 8
8 9
10 5
1 1
6 3
2 2
3 1
4 2


Sample output 1：
0
1
0
1
1
*/