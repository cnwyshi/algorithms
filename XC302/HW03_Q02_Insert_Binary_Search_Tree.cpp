#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    vector<vector<int>> nodes(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        nodes[i + 1].push_back(x);
        nodes[i + 1].push_back(y);
    }
    // dfs(1, nodes);
    return 0;
}
/*
Sample Input:
3
2 3
-1 -1
-1 -1


Sample Output:
2 1 3
*/