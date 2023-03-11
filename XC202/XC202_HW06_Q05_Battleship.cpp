#include<bits/stdc++.h>
using namespace std;

int minx, miny, maxx, maxy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool valid (int x, int y, vector<vector<int>> visited, vector<vector<int>> grid){
    if (x >= 0 && y >= 0 && x < r && y < c && visited[x][y] == 0 && grid[x][y] == '#'){
        return true;
    }
    return false;
}

void search(int x, int y, vector<vector<int>> visited, vector<vector<int>> grid) {
    queue<pair<int, int>> q;
    q.push({x,y});
    while (!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        if (!valid(cur.first, cur.second, visited, grid)) continue;
        visited[cur.first][cur.second] = true;
        minx = min(minx, cur.first);
        maxx = max(maxx, cur.first);
        miny = min(miny, cur.second);
        maxy = max(maxy, cur.second);
        for (int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            q.push({nx, ny});
        }
    }
}

bool rectangle(){
    for (int i = minx; i <= maxx; i++){
        for (int j = miny; j <= maxy; j++){
            if (grid[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int r, c;
    vector<vector<char>> grid()
    int ans = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (!visited[i][j] && grid[i][j] == '#'){
                minx = maxx = i;
                miny = maxy = j;
                search(i, j);
                if (!rectangle()){
                    cout << "Bad placement.";
                    return 0;
                }
                ans++;
            }
        }
    }
    cout << "There are " << ans << " ships.";
}