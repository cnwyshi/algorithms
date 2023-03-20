#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b, zero;
    vector<int> levels(n);
    cin >> n >> a >> b;
    a--;
    b--;
    for(int i = 0; i < n; i++){
        cin >> levels[i];
    }
    cin >> zero;
    queue <int> q;
    q.push(a);
    map<int, int> vis;
    vis[a] = 0;
    while(!q.empty()){
        int cnt = q.front();
        q.pop();
        if(cnt == b){
            cout << vis[cnt] << endl;
            return 0;
        }
        int nxt1 = cnt + levels[cnt];
        int nxt2 = cnt - levels[cnt];
        if(vis.find(nxt1) == vis.end() && nxt1 >= 0 && nxt1 < n){
            q.push(nxt1);
            vis[nxt1] = vis[cnt] + 1;
        }
        if(vis.find(nxt1) == vis.end() && nxt2 >= 0 && nxt2 < n){
            q.push(nxt2);
            vis[nxt2] = vis[cnt] + 1;
        }
    }
    cout << -1 << endl;
}
/*
5 1 5
3 3 1 2 5
0
 */