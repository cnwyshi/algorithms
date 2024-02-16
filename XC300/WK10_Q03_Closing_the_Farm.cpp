#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &root, int i) {
    return root[i] == i ? i : (root[i] = find(root, root[i]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> close(n);
    for (int i = 0; i < n; i++) {
        cin >> close[i];
    }
    vector<int> root(n + 1);
    for (int i = 0; i <= n; i++) {
        root[i] = i;
    }
    vector<string> ans(n);
    ans[n - 1] = "YES";
    vector<bool> connected(n);
    connected[close[n - 1]] = true;
    int group = 1;
    for (int i = n - 2; i >= 0; i--) {
        int x = close[i];
        connected[x] = true;
        group++;
        for (int y: graph[x]) {
            if (connected[y]) {
                int rx = find(root, x), ry = find(root, y);
                if (rx != ry) {
                    root[rx] = ry;
                    group--;
                }
            }
        }
        ans[i] = group == 1 ? "YES" : "NO";
    }
    for (string s: ans) {
        cout << s << endl;
    }
}
/*
Sample Input:
4 3
1 2
2 3
3 4
3
4
1
2
SAMPLE OUTPUT:
YES
NO
YES
YES

1 2
2 3
3 4
remaining

YES initially
3 NO close 3
4 YES close 4
1 YES close 1
2

add 2 YES graph: 2
add 1 YES graph: 2-1
add 4 NO graph: 4 2-1
add 3 YES graph: 4-3-2-1

3
4
1
2

convert edge to graph
1 2
2 3
3 4
=> [[], [2], [1,3], [2,4], [3]]
*/