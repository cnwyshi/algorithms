#include <bits/stdc++.h>
using namespace std;
void dfs(int root, vector<vector<int>>& nodes){
    if(!root) return;
    if(nodes[root][0] != -1){
        dfs(nodes[root][0], nodes);
    }
    cout << root << endl;
    if(nodes[root][1] != -1){
        dfs(nodes[root][1], nodes);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    vector<vector<int>> nodes(n+1);
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        nodes[i+1].push_back(x);
        nodes[i+1].push_back(y);
    }
    dfs(1, nodes);
    return 0;
}
/*
Sample Input:
3
2 3
-1 -1
-1 -1


Sample Output:
2 1 3
*/