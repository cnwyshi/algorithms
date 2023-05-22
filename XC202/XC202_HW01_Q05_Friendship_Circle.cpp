#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &f, int p, int i, vector<bool> &visited) {
    if (!visited[i]) {
        visited[i] = true;
        for (int j = 0; j < f.size(); j++) {
            if (p != j && i != j && f[i][j] == 1) {
                dfs(f, i, j, visited);
            }
        }
    }
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> f[i][j];
        }
    }

    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(f, -1, i, visited);
            ans++;
        }
    }
    cout << ans << endl;
}

/*
3
1 1 0
1 1 1
0 1 1

 */