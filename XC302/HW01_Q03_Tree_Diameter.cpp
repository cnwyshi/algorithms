#include <bits/stdc++.h>
using namespace std;

//  return the farthest node
//  return [depth, farthest node]
vector<int> bfs(vector<vector<int>>& nodes, int root) {
    int n = nodes.size();
    queue<int> q;
    vector<int> visited(n);
    q.push(root);
    visited[root] = 1;
    int ans = 0, depth = 0;
    for (; !q.empty();) {
        depth++;
        for (int m = q.size(); m > 0; m--) {
            int crt = q.front();
            q.pop();
            for (int adj: nodes[crt]) {
                if (visited[adj] == 0) {
                    visited[adj] = 1;
                    q.push(adj);
                    ans = adj;
                }
            }
        }
    }
    return {depth-1, ans};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> nodes(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    cout << bfs(nodes, bfs(nodes, 1)[1])[0] << '\n';
}
/*
Sample Input 1：

6
2 1
2 3
2 4
2 5
6 5

    5 - 6
    |
1 - 2 - 3
    |
    4
Sample Output 1：

3
 */