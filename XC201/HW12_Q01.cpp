#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;

void flood(vector<vector<char>> &field, vector<vector<int>> &visited, int r, int c, int &ans, int count) {
    if (r < 0 || r >= n || c < 0 || c >= n || field[r][c] == '-' || visited[r][c] == 1) {
        if (count > ans) {
            ans = count;
        }
        count = 0;
        return;
    }
    visited[r][c] = 1;
    count++;
    flood(field, visited, r + 1, c, ans, count);
    flood(field, visited, r, c + 1, ans, count);
    flood(field, visited, r - 1, c, ans, count);
    flood(field, visited, r, c - 1, ans, count);
}

int main() {
    cin >> n;
    int x, y, ans = 0, count = 0;
    vector<vector<char>> field(n, vector<char>(n));
    vector<vector<int>> visited(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == '*') {
                flood(field, visited, i, j, ans, count);
            }
        }
    }
    cout << ans;
}
/*
4
-_-*
---_
_---
_---

4
*___
____
____
____
*/

