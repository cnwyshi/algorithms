#include <vector>

using namespace std;

class Solution {
public:
    bool isBattleshipsStart(vector<vector<char>> &board, vector<vector<int>> &visited, int r, int c) {
        int m = board.size(), n = board[0].size();
        //cout <<r << " " << c << endl;
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '.' || visited[r][c] == 1) {
            return false;
        }
        visited[r][c] = 1;
        isBattleshipsStart(board, visited, r - 1, c);
        isBattleshipsStart(board, visited, r, c - 1);
        isBattleshipsStart(board, visited, r, c + 1);
        isBattleshipsStart(board, visited, r + 1, c);
        return true;
    }

    int countBattleships(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (visited[i][j] == 1) {
                    continue;
                }
                if (isBattleshipsStart(board, visited, i, j)) {
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
