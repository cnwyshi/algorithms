#include <iostream>
#include <vector>

using namespace std;

bool isLakeStart(vector<vector<int>> farm, vector<vector<int>>& visited, int r, int c){
    // cout << r << " " << c << endl;
    int m = farm.size(), n = farm[0]. size();
    if(r < 0 || r >= m || c < 0|| c >= n|| farm[r][c] == 0 || visited[r][c] == 1){
		 return false;
	}
	visited[r][c] = 1;
	isLakeStart(farm, visited, r-1, c-1);
	isLakeStart(farm, visited, r-1, c);
	isLakeStart(farm, visited, r-1, c+1);
	isLakeStart(farm, visited, r, c-1);
	isLakeStart(farm, visited, r, c+1);
	isLakeStart(farm, visited, r+1, c-1);
	isLakeStart(farm, visited, r+1, c);
	isLakeStart(farm, visited, r+1, c+1);
	return true;
}
int main(){
    int m, n, ans = 0;
    cin >> m >> n;
    vector<vector<int>> farm (m, vector<int> (n));
    vector<vector<int>> visited (m, vector<int> (n));
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            farm[i][j] = s[j] - '0';
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
             if(isLakeStart(farm, visited, i, j)){
                 ans++;
             }
        }
    }
    cout << ans;
    return 0;
}
