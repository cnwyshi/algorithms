#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, int i, int p, vector<int> &dp) {
    int children = 0;
    for (int c: graph[i]) {
        if (c != p) {
            dfs(graph, c, i, dp);
            children += dp[c];
        }
    }
    dp[i] = 1 + children;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> dp(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph, 1, -1, dp);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << endl;
    }
}
