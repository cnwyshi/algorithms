#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n = 0, ans = 0;
    cin >> n;
    vector<vector<int>> rows(n,vector<int> (n));
    vector<vector<int>> results(n,vector<int> (n));

    for(int i = 0; i<n; i++){
        for(int j = 0; j <= i; j++){
            cin >> rows [i][j];
            results[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int up_left = 0, up = 0;
            if( ( i - 1) >= 0 && (j - 1) >= 0 ) up_left = results[i-1][j-1];
            if( ( i - 1) >= 0 ) up = results[i-1][j];
            results[i][j] = max(up, up_left) + rows[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        ans = max(ans, results[n-1][i]);
    }
    cout << ans;
}