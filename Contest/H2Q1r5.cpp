#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<vector<int>> &adj, ll u, ll p, vector<vector<int>> &ancestor) {
    ancestor[u][0] = p;
    for (ll i = 1; (1 << i) <= adj.size() - 1; i++) {
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
    for (auto v: adj[u]) {
        if (v != p) {
            dfs(adj, v, u, ancestor);
        }
    }
}


int solve() {
    ll n, q;
    cin >> n >> q;
    ll m = log(n) / log(2);
    vector<vector<int>> adj(n + 1), ancestor(n + 1, vector<int>(m));
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj, 1, 0, ancestor);

    for (ll i = 0; i < q; ++i) {
        ll x, k;
        cin >> x >> k;
        for (ll j = m; j >= 0; j--) {
            if (k & (1 << j)) {
                x = ancestor[x][j];
            }
        }
        cout << x << '\n';
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*
输出格式：

q行，每行1个整数表示答案。



样例输入1：

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
          7
         /
1---2---4---6
 \      \
  \      8---9
   3---5---10

样例输出1：
0
1
0
1
1

===

10 7
1 2
3 5
1 3
4 2
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
5 1
10 2


 */