//
// Created by genius on 1/2/2023.
//

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

void dfs(vector<vector<char>> &maze, int turns, int k, int n, int &ans, int i, int j, char cur) {
    if (turns > k || i >= n || j >= n || maze[i][j] == 'H') {
        return;
    }
//    cout << i << " " << j << " " << turns << " " << ans << endl;
    if (i == n - 1 && j == n - 1) {
        ans++;
        return;
    }
    if (cur == 'R') {
        dfs(maze, turns + 1, k, n, ans, i + 1, j, 'D');
        dfs(maze, turns, k, n, ans, i, j + 1, cur);
    } else {
        dfs(maze, turns + 1, k, n, ans, i, j + 1, 'R');
        dfs(maze, turns, k, n, ans, i + 1, j, cur);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> maze(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        int turns = 0, ans = 0;
        dfs(maze, turns, k, n, ans, 0, 1, 'R');
        dfs(maze, turns, k, n, ans, 1, 0, 'D');
        cout << ans << endl;
    }
    return 0;
}
/*
1
 3 1
 . . .
 . . .
 . . .
*/