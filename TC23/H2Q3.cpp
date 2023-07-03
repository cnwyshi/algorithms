#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll parent[100001];
map<ll, vector<ll>> adj;
ll binary[100001][200];
ll n, q;
ll depth[100001];

void dfs(ll node) {
    binary[node][0] = parent[node];
    for (ll l = 1; (1 << l) <= n; ++l) {
        binary[node][l] = binary[binary[node][l - 1]][l - 1];
    }
    for (auto child: adj[node]) {
        depth[child] = depth[node] + 1;
        dfs(child);
    }
}

ll lca(ll a, ll b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    ll k = depth[a] - depth[b];
    for (ll l = log(n) / log(2); l >= 0; --l) {
        if (k & (1 << l)) {
            a = binary[a][l];
        }
    }
    if (a == b) {
        return a;
    }
    for (ll l = log(n) / log(2); l >= 0; --l) {
        if (binary[a][l] != binary[b][l]) {
            a = binary[a][l], b = binary[b][l];
        }
    }
    return parent[a];
}


int solve() {
    cin >> n >> q;
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
    dfs(1);

    for (ll i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }


    return 0;
}

#ifndef MY_UNIT_TEST

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

#endif