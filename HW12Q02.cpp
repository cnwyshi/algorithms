#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& map, vector<vector<int>>& visited, int r, int c, int steps, int& ans, char destination){
    int n = map.size();
//    cout << map[r][c] << " " << r << " " << c << " " << steps << " " << ans << endl;
    if(r < 0 || c < 0 || r >= n || c >= n || map[r][c] == 'X' || visited[r][c] == 1){
        return;
    }
//    cout << map[r][c] << " " << r << " " << c << " " << steps << " " << ans << endl;
    if(steps > ans){
        return;
    }
    if(map[r][c] == destination){
        ans = steps;
        steps = 0;
        return;
    }
//    cout << "hi" << endl;
    visited[r][c] = 1;
    dfs(map, visited, r+1, c, steps+1, ans, destination);
    dfs(map, visited, r-1, c, steps+1, ans, destination);
    dfs(map, visited, r, c+1, steps+1, ans, destination);
    dfs(map, visited, r, c-1, steps+1, ans, destination);
    visited[r][c] = 0;
}
int main() {
    int n, x, y, x1, x2, y1, y2;
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
//    cout << x2 << " " << y2 << " " << map[x2][y2] << endl;
    dfs(map, visited, x, y, 0, ans, 'M');
    int fast1 = ans;
//    cout << fast1 << endl;
    ans = 123456789;
    map[x2][y2] = '.';
    map[x1][y1] = 'B';
//    cout << x1 << " " << y1 << " " << map[x1][y1] << endl;
    dfs(map, visited, x, y, 0, ans, 'B');
    int fast2 = ans;
//    cout << fast2 << endl;
    if(fast1 < fast2){
        cout << "Mountains " << fast1 << endl;
    }
    if(fast1 > fast2){
        cout << "Beach " << fast2 << endl;
    }
    if(fast1 == fast2){
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