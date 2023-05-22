#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>

using namespace std;
int R, C;
vector<vector<char> > maze;
vector<vector<int> > visited;
// char's gate list
map<char, vector<vector<int> > > gate;
int dirs[4][2] = {{1,  0},
                  {-1, 0},
                  {0,  1},
                  {0,  -1}};

void dfs(int r, int c, int path) {
    if ((r == R - 1) && (c == C - 1)) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int new_r = r + dirs[i][0];
        int new_c = c + dirs[i][1];
        if (new_c >= 0 && new_c < C && new_r >= 0 && new_r < R && maze[new_r][new_c] != '1') {
            if (maze[new_r][new_c] != '0') {
                // transport(new_r,new_c);
                for (int j = 0; j < gate[maze[new_r][new_c]].size(); j++) {
                    int gate_r = gate[maze[new_r][new_c]][j][0];
                    int gate_c = gate[maze[new_r][new_c]][j][1];
                    if (gate_r == new_r && gate_c == new_c) continue;
                    new_r = gate_r;
                    new_c = gate_c;
                    break;
                }
            }
            if (path + 1 < visited[new_r][new_c]) {
                // cout << "new_r: " << new_r << " new_c: " << new_c << " path: " << path << endl;
                visited[new_r][new_c] = path + 1;
                dfs(new_r, new_c, path + 1);
            }
        }
    }
}


int main() {
    cin >> R >> C;
    visited = vector<vector<int>>(R, vector<int>(C, 2 * R * C));
    maze = vector<vector<char>>(R, vector<char>(C, '0'));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
            // if maze[i][j] is a gate, add (i,j) it to the gate list
            if (maze[i][j] != '0' && maze[i][j] != '1') {
                gate[maze[i][j]].push_back(vector<int>{i, j});
            }
        }
    }

    if (maze[0][0] == '0') {
        visited[0][0] = 0;
        dfs(0, 0, 0);
    }
    if (visited[R - 1][C - 1] == 2 * R * C) {
        cout << "No Solution.";
    } else {
        cout << visited[R - 1][C - 1] << endl;
    }

}