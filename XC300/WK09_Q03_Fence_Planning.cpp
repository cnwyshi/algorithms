#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& leader, int i){
    if(leader[i] == i){
        return i;
    }
    else{
        int j = leader[i];
        leader[i] = find(leader, j);
        return leader[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<vector<int>> pos(n+1, vector<int> (2));
    for(int i = 1; i <= n; i++){
        cin >> pos[i][0] >> pos[i][1];
    }
    vector<int> leader(n+1);
    for(int i = 0; i <= n; i++){
        leader[i] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        int ra = find(leader, a), rb = find(leader, b);
        if(ra != rb){
            leader[ra] = rb;
        }
    }
    vector<vector<int>> group(n+1);
    for(int i = 1; i <= n; i++){
        int l = find(leader, i);
        group[l].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(!group[i].empty()){
            int top, bottom, left, right;
            for(int j : group[i]){

            }
        }
    }
}
/*
SAMPLE INPUT:
7 5

0 5
10 5
5 0
5 10
6 7
8 6
8 4

1 2
2 3
3 4
5 6
7 6
SAMPLE OUTPUT:
10

g1: 1,2,3,4
g2: 5,6,7

vector<vector<int>> value =

[[],
 [1,2,3,4],
 [],
 [],
 [],
 [5,6,7],
 [],
 []]
tl: [6, 7]
br: [8, 4]
p = ((8-6)+(7-4))*2
*/