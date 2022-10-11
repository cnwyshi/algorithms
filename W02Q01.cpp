//
// Created by genius on 9/19/22.
//
// First Problem
#include <iostream>
#include <vector>

using namespace std;

int flood_fill(vector<vector<int>>& maze, int r, int c){
    int m = maze.size(), n = maze[0]. size(), count = 0;
    if(r < 0|| r >= m || c < 0 || c >= n|| maze[r][c] == 1){
        return 0;
    }
    maze[r][c] = 1;
    count += flood_fill(maze, r-1, c);
    count += flood_fill(maze, r+1, c);
    count += flood_fill(maze, r-1, c-1);
    count += flood_fill(maze, r+1, c+1);
//    cout << r << " " << c << " " << count <<endl;
    return 1 + count;
}
int main(){
    int n = 0, start_r = 0, start_c = 0;
    cin >> n >> start_r >> start_c;
    vector<vector<int>> maze (n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            cin >> maze[i][j];
        }
    }
    int count = flood_fill(maze, start_r, start_c);
    cout << count << endl;
    return 0;
}

/*3 0 0
0 0 0
0 1 0
1 0 1


 4 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 1*/