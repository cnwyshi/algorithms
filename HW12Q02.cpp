#include <iostream>
#include <vector>

int n, x, y, x1, x2, y1, y2;
using namespace std;

void dfs(vector<vector<char>>& map, vector<vector<int>>& visited, int r, int c, int steps, int& ans, char destination){
    if(x < 0 || y < 0 || x >= n || y >= n || map[x][y] == 'X' || visited[x][y] == 1){
        return;
    }
    cout << map[r][c] << " " << r << " " << c << " " << steps << " " << ans << endl;
    if(steps > ans){
        return;
    }
    if(map[x][y] == destination){
        ans = steps;
        return;
    }
    visited[x][y] = 1;
    dfs(map, visited, r+1, c, steps+1, ans, destination);
    dfs(map, visited, r-1, c, steps+1, ans, destination);
    dfs(map, visited, r, c+1, steps+1, ans, destination);
    dfs(map, visited, r, c-1, steps+1, ans, destination);
    visited[x][y] = 0;
}
int main() {
    cin >> n;
    vector<vector<char>> map (n, vector<char> (n));
    vector<vector<int>> visited (n, vector<int> (n));
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == '@'){
                x = i;
                y = j;
            }
            if(map[i][j] == 'B'){
                x1 = i;
                y1 = j;
            }
            if(map[i][j] == 'M'){
                x2 = i;
                y2 = j;
            }
        }
    }
    int ans = 123456789;
    map[x1][y1] = '.';
    dfs(map, visited, x, y, 0, ans, 'M');
    int fast1 = ans;
    cout << fast1 << endl;
    ans = 123456789;
    map[x2][y2] = '.';
    map[x1][x1] = 'B';
    dfs(map, visited, x, y, 0, ans, 'B');
    int fast2 = ans;
    cout << fast2 << endl;
    if(fast1 < fast2){
        cout << "Mountains " << fast1 << endl;
    }
    if(fast1 > fast2){
        cout << "Beach " << fast2 << endl;
    }
    else{
        cout << "Either " << fast2 << endl;
    }
    return 0;
}
/*
Sample Input:
5
. @ X . .
. . X . .
X . . X B
M . . . .
. . . . .
Sample Output:
Mountains 4
 */