#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<vector<int>>& adj, ll u, ll p, vector<vector<int>>& ancestor, vector<int>& depth) {
    ancestor[u][0] = p;
    for (ll i = 1; (1 << i) <= adj.size() - 1; i ++) {
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
    for (auto v: adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(adj, v, u, ancestor, depth);
        }
    }
}

ll LCA(vector<vector<int>>& ancestor, vector<int>& depth, ll a, ll b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    ll k = depth[a] - depth[b], m = log(depth.size()) / log(2);
    for (ll i = m; i >= 0; --i) {
        if (k & (1 << i)) {
            a = ancestor[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (ll i = m; i >= 0; --i) {
        if (ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i], b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

int solve() {
    ll n, q;
    cin >> n >> q;
    ll m = log(n) / log(2);
    vector<vector<int>> adj(n + 1), ancestor(n + 1, vector<int>(m));
    for (ll i = 0; i < n - 1; i ++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n + 1);
    dfs(adj, 1, 0, ancestor, depth);
    for (ll i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << LCA(ancestor, depth, a, b) << '\n';
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*
样例输入1：

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

样例输出1：

1

1

2

2

1
 */