#include <bits/stdc++.h>

using namespace std;

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
    queue<int> q;
    vector<int> visited(n);
    q.push(0);
    visited[0] = 1;
    size_t depth = 0;
    for (; !q.empty();) {
        for (int m = q.size(); m > 0; m--) {
            int crt = q.front();
//            cout << crt << endl;
            q.pop();
            for (int adj: nodes[crt]) {
                if (visited[adj] == 0) {
                    visited[adj] = 1;
                    q.push(adj);
                }
            }
        }
        depth = max(depth, q.size());
    }
    cout << depth << endl;
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
4
 */