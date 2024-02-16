#include <bits/stdc++.h>

using namespace std;
static const auto fast = []() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int bellman_ford(int n, vector<vector<int>> &edge, int s, int t) {
    vector<int> dist(n + 1, INT_MAX / 2);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (vector<int> &e: edge) {
            int a = e[0], b = e[1];
            dist[b] = min(dist[b], dist[a] + 1);
        }
    }
    return dist[t] == INT_MAX / 2 ? -1 : dist[t];
}

int main() {
    int n, m, a, b, s, t;
    cin >> n >> m;
    vector<vector<int>> edge;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge.push_back({a, b});
        edge.push_back({b, a});
    }
    cin >> s >> t;
    cout << bellman_ford(n, edge, s, t) << endl;
    return 0;
}

/*
时间：1s   空间：32M

题目描述：
给你一副无向图，不保证连通，求图上两点间的最短路，每条边的长度都是1

输入格式：
第一行输入两个整数n,m,分别表示点与边的数量

接下来m行每行输入两个整数a,b，表示一条边

最后一行输入两个整数s,t,表示起点和终点


输出格式：
输出s,t之间的最短路，如果s,t不可达，输出-1



样例输入：
4 4
1 2
1 3
2 4
3 4
1 4


样例输出：
2


约定：
1<=n<=5000,1<=m<=8000


提示：
 */