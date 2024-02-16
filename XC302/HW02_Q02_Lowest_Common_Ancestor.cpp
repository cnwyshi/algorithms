#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int u, int p, vector<int> &parent, vector<int> &depth) {
    for (int v: adj[u]) {
        if (v != p) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(adj, v, u, parent, depth);
        }
    }
}

int main() {
    int n, a, b, p, m = 1;
    cin >> n >> a >> b;
    vector<vector<int>> adj(n + 1);
    string s, c;
    while (getline(cin, s) && m < n) {
        istringstream iss(s);
        iss >> p;
        while (iss) {
            iss >> c;
            adj[p].push_back(stoi(c));
            adj[stoi(c)].push_back(p);
        }
        m++;
    }
    vector<int> parent(n + 1), depth(n + 1);
    dfs(adj, 1, 0, parent, depth);
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; i < diff; i++) {
        a = parent[a];
    }
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    cout << a << endl;
}
/*
Sample Input:
9 3 6
1 3 4 2
3 8 5
4 9 6 7

Sample Output:
1


15 2 10
1 2 8
2 3 4
3 5
4 6 11
6 7 12
7 9 15
8 14
9 10 13





*/