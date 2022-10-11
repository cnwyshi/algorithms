#include <iostream>
#include <vector>

using namespace std;

int flood_fill(vector<vector<char>>& maze, int r, int c){
    int m = maze.size(), n = maze[0]. size(), count = 0;
    if(r < 0|| r >= m || c < 0 || c >= n|| maze[r][c] == '#'){
        return 0;
    }
    maze[r][c] = '#';
    count += flood_fill(maze, r-1, c);
    count += flood_fill(maze, r+1, c);
    count += flood_fill(maze, r, c-1);
    count += flood_fill(maze, r, c+1);
//    cout << r << " " << c << " " << count <<endl;
    return 1 + count;
}
int main(){
    int n = 0, m = 0, r = 0, c = 0;
    cin >> n >>m;
    vector<vector<char>> maze (m, vector<char> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '@'){
                r = i;
                c = j;
            }
        }
    }
    int count = flood_fill(maze, r, c);
    cout << count << endl;
    return 0;
}