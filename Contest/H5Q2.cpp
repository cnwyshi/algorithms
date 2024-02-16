#include <bits/stdc++.h>

using namespace std;
static const auto fast = []() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

bool negative_cycle(int n, vector<vector<int>> &edge) {
    vector<int> dist(n + 1);
    for (int i = 0; i < n - 1; i++) {
        for (vector<int> &e: edge) {
            int a = e[0], b = e[1], w = e[2];
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    for (vector<int> &e: edge) {
        int a = e[0], b = e[1], w = e[2];
        if (dist[b] > dist[a] + w) {
            return true;
        }
    }
    return false;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> m;
        vector<vector<int>> edge(m, vector<int>(3));
        for (int i = 0; i < m; i++) {
            cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        }
        cout << (negative_cycle(n, edge) ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
B.  判断负环
Problem ID: 1071
Contest ID: 5670
必做题
给Case张可能有重边和自环，也可能不连通的带权有向图，请判断他们有没有负环，有则输出YES，没有则输出NO。



输入格式：
一个数Case表示图的张数

以后每张图两个n,m表示 这张图的点数和边数

接下来m行 每行三个数 xi,yi,zi 表示一条xi-yi 权值为z的边



输出格式：
Case行 第i行表示第i张图有没有负环

有输出YES 没有输出NO



样例输入：
2
1 1
1 1 -1
4 4
1 2 1
2 1 1
3 4 -2
4 3 1


样例输出：
YES
YES


数据范围：
Case<=20

N<=100

M<=500



时间限制：
1000



空间限制：
65536
 */