#include <vector>

using namespace std;

class Solution {
public:
    bool isIslandStart(vector<vector<char>> &grid, vector<vector<int>> &visited, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        // cout <<r << " " << c << endl;
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0' || visited[r][c] == 1) {
            return false;
        }
        visited[r][c] = 1;
        isIslandStart(grid, visited, r - 1, c);
        isIslandStart(grid, visited, r, c - 1);
        isIslandStart(grid, visited, r, c + 1);
        isIslandStart(grid, visited, r + 1, c);
        return true;
    }

    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (visited[i][j] == 1) {
                    continue;
                }
                if (isIslandStart(grid, visited, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}

