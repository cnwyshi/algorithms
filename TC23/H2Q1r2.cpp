#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(vector<vector<int>>& adj, vector<int>& parent, ll node, vector<vector<int>>& binary) {
    binary[node][0] = parent[node];
    for (ll l = 1; (1 << l) <= parent.size() - 1; ++l) {
        binary[node][l] = binary[binary[node][l - 1]][l - 1];
    }
    for (auto child: adj[node]) {
        dfs(adj, parent, child, binary);
    }
}


int solve() {
    ll n, q;
    cin >> n >> q;
    vector<int> parent(n + 1);
    vector<vector<int>> adj(n + 1), binary(n + 1, vector<int>(200));
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        if ((parent[a] == 0 && a != 1) || b == 1) {
            parent[a] = b;
            adj[b].push_back(a);
        } else {
            parent[b] = a;
            adj[a].push_back(b);
        }
    }
    dfs(adj, parent, 1, binary);

    for (ll i = 0; i < q; ++i) {
        ll x, k;
        cin >> x >> k;
        for (ll l = log(n) / log(2); l >= 0; --l) {
            if (k & (1 << l)) {
                x = binary[x][l];
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