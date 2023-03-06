// Source: https://usaco.guide/general/io

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
//You can move up, down, top-left, bottom-right for each one step.
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, -1, 1, 2, -2, 2, -2};
int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    sx--;
    sy--;
    // cout << n << " " << m << endl;
    queue<pair<int, int>> q;
    vector<vector<int>> grid(n, vector<int>(m));
    grid[sx][sy] = 0;
    vector<vector<bool>> visited(n, vector<bool>(m));
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    int steps = 1;
    for(; !q.empty(); steps++){
        for(int s = q.size(); s > 0; s--){
            int cx = q.front().first, cy = q.front().second;
            // cout << cx << " " << cy << endl;
            q.pop();
            for(int i = 0; i < 8; i++){
                int nx = cx + dx[i], ny = cy + dy[i];
                // cout << nx << " " << ny << endl;
                // cout << n << " " << m << endl;
                // cout << sx << " " << sy << endl;
                // cout << (nx >= 0 && ny >= 0 && nx < n && ny < m) << " " << (!visited[nx][ny]) << endl;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]){
                    q.push(make_pair(nx, ny));
                    // cout << nx << " " << ny << endl;
                    grid[nx][ny] = steps;
                    visited[nx][ny] = true;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                grid[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
/*
3 3 1 1

0    3    2
3    -1   1
2    1    4
*/