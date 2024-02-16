#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &nodes, int root) {
    int n = nodes.size();
    vector<int> dist(n + 1);
    queue<int> q;
    vector<int> visited(n);
    q.push(root);
    visited[root] = 1;
    int depth = 0;
    for (; !q.empty();) {
        depth++;
        for (int m = q.size(); m > 0; m--) {
            int crt = q.front();
            q.pop();
            for (int adj: nodes[crt]) {
                if (visited[adj] == 0) {
                    visited[adj] = 1;
                    q.push(adj);
                    dist[n] = adj;
                    dist[adj] = depth;
                }
            }
        }
    }
    return dist;
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
    vector<int> dist1 = bfs(nodes, 0);
    vector<int> dist2 = bfs(nodes, dist1[n]);
    vector<int> dist3 = bfs(nodes, dist2[n]);
    for (int i = 0; i < n; i++) {
        cout << max(dist2[i], dist3[i]) << " ";
    }
    cout << endl;
    return 0;
}
/*
Input:
5
1 2
1 3
3 4
3 5

Output:
2 3 2 3 3

4 - 3 - 1 - 2
    |
    5

    1
  /  \
  3  2
 / \
4  5


root = 5
dist1 = [2, 3, 1, 2, 0]
farthest = 2

root = 2
dist2 = [1, 0, 2, 3, 3]
 */