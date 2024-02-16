#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int u, vector<int> &depth) {
    for (auto v: adj[u]) {
        depth[v] = depth[u] + 1;
        dfs(adj, v, depth);
    }
}

int lca(vector<int> &depth, vector<int> &parent, int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    while (depth[a] < depth[b]) {
        b = parent[b];
    }

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;

}

int solve() {
    string line, c;
    int n, a, b, p;
    cin >> n >> a >> b;
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1), depth(n + 1);
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> p;
        while (iss >> c) {
            adj[p].push_back(stoi(c));
            parent[stoi(c)] = p;
        }
    }
    dfs(adj, 1, depth);
    cout << lca(depth, parent, a, b);

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*
样例输入：
9 3 6
1 3 4 2
3 8 5
4 9 6 7


样例输出：
1
*/