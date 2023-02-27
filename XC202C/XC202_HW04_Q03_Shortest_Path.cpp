#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//You can move up, down, top-left, bottom-right for each one step.
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    int steps = 1;
    for(; !q.empty(); steps++){
        for(int m = q.size(); m > 0; m--){
            int cx = q.front().first, cy = q.front().second;
            if(cx == n-1 && cy == n-1){
                cout << steps << "\n";
                return 0;
            }
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i], ny = cy + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != 1 && visited[nx][ny] != true){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
    cout << -1 << "\n";
}
/*
3
0 0 0
1 0 1
0 0 0

step = 1, q = [[0, 0]]
step = 2, q = [[0, 1]]
step = 3, q = [[0, 2], [1, 1]]







3
0 1 0
1 0 1
0 0 0
steps = 1, q = [[0, 0]]
steps = 2, q = [[]]
*/