#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &farm, vector<vector<int>> &visited, int r, int c) {
    // cout << r << " " << c << endl;
    int m = farm.size(), n = farm[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || farm[r][c] == 0 || visited[r][c] == 1) {
        return 0;
    }
    int area = 1;
    visited[r][c] = 1;
    area += dfs(farm, visited, r - 1, c);
    area += dfs(farm, visited, r, c - 1);
    area += dfs(farm, visited, r, c + 1);
    area += dfs(farm, visited, r + 1, c);
    return area;
}

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    vector<vector<int>> farm(m, vector<int>(n));
    vector<vector<int>> visited(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            farm[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int area = dfs(farm, visited, i, j);
            ans = max(ans, area);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
5 4
0101
0111
1000
1100
0101

1 3
111
 */