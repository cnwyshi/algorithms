#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
//You can move up, down, top-left, bottom-right for each one step.
int dx[4] = {1, -1, 1, -1};
int dy[4] = {0, 0, 1, -1};
int main() {
    int n, x, y, count = 0;
    cin >> n >> x >> y;
    queue<pair<int, int>> q;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> visited(n, vector<int>(n));
    visited[x][y] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        count++;
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < n && ny < n && nx >= 0 && ny >= 0 && grid[nx][ny] != 1 && visited[nx][ny] != 1){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     cout << visited[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    cout << count << endl;
}
/*
3 0 0
0 0 0
0 1 0
1 0 1
*/