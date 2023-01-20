//
// Created by genius on 1/8/23.
//
#include <iostream>
#include <vector>
using namespace std;
vector<bool> vis;
bool good(int a, int b){
    return !vis[b] && matrix[a][b] == 1;
}
void dfs(int i){
    int n = vis.size();
    if(vis[i]){
        return;
    }
    for(int j = 0; j < n; j++){
        if(good)
    }
}
int main() {
    int n, ans = 0;
    cin >> n;
    vis.resize(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans++;
            dfs[i];
        }
    }
}