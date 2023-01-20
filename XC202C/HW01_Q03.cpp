#include <iostream>
#include <vector>

using namespace std;

bool isLakeStart(vector<vector<char>>& farm, vector<vector<int>> &visited, int r, int c) {
    int m = farm.size(), n = farm[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || farm[r][c] == '#' || visited[r][c] == 1) {
        return false;
    }
    visited[r][c] = 1;
    isLakeStart(farm, visited, r - 1, c);
    isLakeStart(farm, visited, r, c - 1);
    isLakeStart(farm, visited, r, c + 1);
    isLakeStart(farm, visited, r + 1, c);
    return true;
}

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    bool all = true;
    vector<vector<char>> farm(m, vector<char>(n));
    vector<vector<int>> visited(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> farm[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isLakeStart(farm, visited, i, j)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
