#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
static const auto fast = []() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();


int solve() {
    int n, w;
    cin >> n;
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "No Solution";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

int main() {
    solve();
}

/*
题目描述
提交记录
B.  [模板]Floyd算法
Problem ID: 7500
Contest ID: 5258
必做题
时间限制：2s    空间限制：128M
题目描述
这是一道模板题。

有一张 n 个点的带边权的有向图，以邻接矩阵的方式给出，保证每个点到自己的边权是 0 。

你需要求出图中任意两点间的最短路径。特别的，一个点到自己的最短路径为 0。

如果图中存在负环，则只需要输出一行 "No Solution"（不包含引号）。

输入格式
第一行一个整数 n，表示图的点数。

接下来 n 行，每行 n 个数，其中第 i 行第 j 列的数表示点 i 到点 j 的边的边权。

输出格式
输出 n 行，每行 n 个数，其中第 i 行第 j 列的数表示点 i 到点 j 的最短路径。

输入样例1：
3
0 1 2
-1 0 0
2 1 0
输出样例1：
0 1 1
-1 0 0
0 1 0
输入样例2:
2
0 1
-2 0
输出样例2:
No Solution
数据规模与约定

对于10%的数据，n ≤ 5 ，图中的边权都为非负数。

对于100%的数据，n ≤ 500 ，边权为 [-65536, 65536] 之间的整数。
*/
