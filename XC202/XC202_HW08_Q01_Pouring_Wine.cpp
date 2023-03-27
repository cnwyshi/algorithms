#include <bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if(A % 2 == 1){
        cout << -1 << endl;
    }
    vector<int> start = {A, 0, 0};
    queue<vector<int>> q;
    q.push(start);
    map<vector<int>, int> vis;
    vis[start] = 0;
    while(!q.empty()){
        vector<int> crt = q.front();
        int a = crt[0], b = crt[1], c = crt[2];
        if((a == b && c == 0) || (b == c && a == 0) || (c == a && b == 0)){
            cout << vis[crt] << endl;
        }
        q.pop();
        //pour a to b
        int move = min(a, B-b);
        if(move > 0){
            vector<int> nxt ={a-move, b+move, c};
            if(vis.find(nxt) == vis.end()){
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
        //pour a to c
        move = min(a, C-c);
        if(move > 0){
            vector<int> nxt ={a-move, b, c+move};
            if(vis.find(nxt) == vis.end()){
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
        //pour b to a
        move = min(b, A-a);
        if(move > 0){
            vector<int> nxt ={a+move, b-move, c};
            if(vis.find(nxt) == vis.end()){
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
        //pour b to c
        move = min(b, C-c);
        if(move > 0){
            vector<int> nxt ={a, b-move, c+move};
            if(vis.find(nxt) == vis.end()){
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
        //pour c to a
        move = min(c, A-a);
        if(move > 0){
            vector<int> nxt ={a+move, b, c-move};
            if(vis.find(nxt) == vis.end()){
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
        //pour c to b
        move = min(c, B-b);
        if(move > 0){
            vector<int> nxt ={a, b+move, c-move};
            if(vis.find(nxt) == vis.end()){
                q.push(nxt);
                vis[nxt] = vis[crt] + 1;
            }
        }
    }
    cout << "NO" << endl;
}
/*
from position x to position y
int diff = x - y;
if(diff < 0){

 }
 */