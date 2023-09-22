#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
static const auto fast = []() { std::ios_base::sync_with_stdio(0); cin.tie(0); return 0;}();

void path(vector<vector<ll>>& dist, vector<vector<ll>>& parent, ll s, ll t) {
    cout << dist[s][t] << "\n";
    vector<ll> path{t};
    while (s != t) {
        t = parent[s][t];
        path.push_back(t);
    }
    std::reverse(path.begin(), path.end());
    for (auto &node: path) {
        cout << node << " ";
    }
    cout << '\n';
}

/*
 +---------4---(20)--+
 |         |         |
(2)       (3)        |
 |         |         |
 1---(6)---2---(4)---3
 |                   |
(23)                 |
 |                   |
 5---(7)-------------+
 */

int solve() {
    ll s1, t1, s2, t2, n, m, a, b, c;
    cin >> s1 >> t1 >> s2 >> t2;
    cin >> n >> m;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
    vector<vector<ll>> parent(n + 1, vector<ll>(n + 1, inf));
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
        parent[a][b] = a;
        parent[b][a] = b;
    }
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // i------k----x--j
                    parent[i][j] = parent[k][j];
                } else if (dist[i][j] == dist[i][k] + dist[k][j]) {
                    if (parent[k][j] != j) {
                        parent[i][j] = min(parent[i][j], parent[k][j]);
                    }
                }
            }
        }
    }
    path(dist, parent, s1, t1);
    path(dist, parent, s2, t2);
    return 0;
}


int main() {
    solve();
}

/*
C.  费洛伊德算法（求路径）
Problem ID: 1062
Contest ID: 5258
选做题
时间限制：1s    空间限制：512M


题目描述：
用费洛伊德（Floyd）算法求任意两点最短路径。
分别输出给定两对结点最短路径值，并依次列出其路径结点。

输入格式：
第一行二个整数 s1,t1；
第二行二个整数 s2,t2；
第三行二个整数 n,m；(n≤200, m≤40000)
随后 m 行每行三个整数 a,b,c，表示 a, b 之间有一条权值为 c 的边。(c≤109)

输出格式：
s1 到 t1 的最短路，并输出路径（按字典序输出最小的一条）
s2 到 t2 的最短路，并输出路径（按字典序输出最小的一条）

样例输入：
1 3
2 5
5 7
1 2 6
1 4 2
1 5 23
2 3 4
2 4 3
3 4 20
3 5 7


样例输出：
9
1 4 2 3
11
2 3 5


 +---------4---(20)--+
 |         |         |
(2)       (3)        |
 |         |         |
 1---(6)---2---(4)---3
 |                   |
(23)                 |
 |                   |
 5---(7)-------------+
*/