#include <bits/stdc++.h>
using namespace std;
static const auto fast = []() { std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

int negative_cycle(int n, vector<vector<int>>& edge, vector<int>& prev) {
    vector<int> dist(n + 1);
    for (int i = 0; i < n - 1; i ++) {
        for (vector<int>& e : edge) {
            int a = e[0], b = e[1], w = e[2];
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                prev[b] = a;
            }
        }
    }
    for (vector<int>& e : edge) {
        int a = e[0], b = e[1], w = e[2];
        if (dist[a] + w < dist[b]) {
            return b;
        }
    }
    return -1;
}

vector<int> path(int n, vector<int>& prev, int t) {
    vector<int> visited(n + 1), path;
    for (int i = t; !visited[i]; i = prev[i]) {
        path.push_back(i);
        visited[i] = 1;
    }
    path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(m, vector<int>(3));
    for (int i = 0; i < m; i ++) {
        cin >> edge[i][0] >> edge[i][1] >>edge[i][2];
    }
    vector<int> prev(n + 1, -1);
    int t = negative_cycle(n, edge, prev);
    if (t > 0) {
        cout << "YES ";
        for (int i : path(n, prev, t)) {
            cout << i << " ";
        }
    } else {
        cout << "NO";
    }
    return 0;
}

/*
C.  Cycle Finding
Problem ID: 14071
Contest ID: 5670
必做题
时间限制: 1.00 s

空间限制: 512 MB

给定一个有向图，判断其中是否存在负环，并输出一个负环。

输入

第一行两个整数 n 和 m，分别表示图中节点数和边数。节点编号为 1 到 n。接下来 m 行，每行三个整数 a、b、c，表示存在一条从节点 a 指向节点 b，边权为 c 的边。

输出

如果图中存在负环，则输出 "YES" 和构成负环的节点序列；否则输出 "NO"。

限制

1≤n≤2500，1≤m≤5000，1≤a,b≤n，−109≤c≤109。

样例

样例输入

4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2



样例输出

YES 1 2 4 1
 */