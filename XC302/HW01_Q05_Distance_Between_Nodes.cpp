#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &nodes, int root) {
    int n = nodes.size();
    vector<int> dist(n);
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            if (x == '1') {
                nodes[i].push_back(j);
                nodes[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> dist = bfs(nodes, i);
        for (int d: dist) {
            cout << d << " ";
        }
        cout << endl;
    }
}
/*
Sample Input:
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000


Sample Output:
0 1 1 2 2 2 3 4 4 2
1 0 2 1 3 3 4 5 5 3
1 2 0 3 1 1 2 3 3 1
2 1 3 0 4 4 5 6 6 4
2 3 1 4 0 2 3 4 4 2
2 3 1 4 2 0 1 2 2 2
3 4 2 5 3 1 0 1 1 3
4 5 3 6 4 2 1 0 2 4
4 5 3 6 4 2 1 2 0 4
2 3 1 4 2 2 3 4 4 0
 */