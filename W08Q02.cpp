//
// Created by genius on 11/3/22.
//

//
// Created by genius on 10/1/22.
//

#include <iostream>
#include <vector>

using namespace std;
bool vis[11];
void permutations(int n,int m, vector<vector<int>>& cows, vector<int> a, int& ans) {
    if(m == n){
        bool match = true;
        // for(int i = 0; i < n; i++){
        //     cout << a[i] << " ";
        // }
        //cout << endl;
        for(int i = 1; i<n; i++){
            if(cows[i-1][0] != cows[i][0] || cows[i-1][1] != cows[i][1]){
                match = false;
                break;
            }
        }
        if( match){
            ans ++;
        }
        return;
    }
    else{
        for(int i = 1; i<=n; i++){
            if(vis[i] != 0) continue;
            vis[i] = 1;
            a[m] = i;
            permutations(n,m+1, cows, a, ans);
            vis[i] = 0;
        }
    }
}


int main() {
    int n;
    int ans = 0;
    vector<vector<int>> cows(n, vector<int>(2));
    vector<int> a (n);
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 2; j ++){
            cin >> cows[i][j];
        }
    }
    permutations(n, 0, cows, a, ans);
    cout << ans;
}
/*
4
0 1
2 1
2 0
2 -5

vector<vector<char>> maze (n, vector<char> (m));
*/