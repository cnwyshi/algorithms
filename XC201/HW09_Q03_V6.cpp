#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int ret, visited[100000][21][3];

// http://www.usaco.org/index.php?page=viewproblem2&cpid=694
void dfs(vector<int>& a, int i, int k, int c, int s) {
    if (i == a.size()) {
        ret = max(ret, s);
        return;
//    } else if (visited[i][k][c]) {
//        return;
    }
    visited[i][k][c] = true;
    // PSH, current color (c) wins if it follows a[i] in circle
    if ((c + 3 - a[i]) % 3 == 1) {
        dfs(a, i + 1, k, c, s + 1);
    } else {
        dfs(a, i + 1, k, c, s);
        if (k > 0) {
            dfs(a, i + 1, k - 1, (a[i] + 1) % 3, s + 1);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        a[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    for (int j = 0; j < 3; j ++) {
        dfs(a, 0, k, j, 0);
    }
    cout << ret << endl;
    return 0;
}

/*
100 13
S
H
H
P
H
S
P
H
P
S
S
S
H
H
P
S
H
P
H
P
P
P
P
H
H
S
P
P
P
P
H
S
P
S
H
P
P
S
S
H
P
S
S
S
H
H
P
P
P
S
H
H
P
S
H
P
P
H
P
S
H
P
P
P
P
S
P
H
S
H
H
H
S
H
P
S
S
S
S
S
S
S
S
H
P
S
H
H
S
P
H
H
H
P
H
H
S
S
P
S
*/