#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> maze, vector<vector<int>>& visited,  int r, int c, int& count, int& ans, int steps){
    int n = maze.size();
	if(r < 0 || r >= n || c < 0|| c >= n|| maze[r][c] == 1 || visited[r][c] == 1){
		 return;
	}
	if(r == n-1 && c == n-1){
		count++;
		if(steps < ans){
			ans = steps;
		}
		return;
	}
	visited[r][c] = 1;
	dfs(maze, visited, r+1, c, count, ans, steps + 1);
	dfs(maze, visited, r-1, c, count, ans, steps + 1);
	dfs(maze, visited, r, c+1, count, ans, steps + 1);
	dfs(maze, visited, r, c-1, count, ans, steps + 1);
	visited[r][c] = 0;
}
int main(){
    int n, count = 0;
	cin >> n;
	vector<vector<int>> maze (n, vector<int> (n));
	vector<vector<int>> visited (n, vector<int> (n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> maze [i][j];
		}
	}
	if(maze [0][0] == 1 || maze[n-1][n-1] == 1){
		cout << -1 << endl;
		return 0;
	}
	int ans = n*n;
	dfs(maze, visited, 0, 0, count, ans, 1);
	if(count < 1){
		cout << -1 << endl;
		return 0;
	}
	cout << ans;
	return 0;
}
