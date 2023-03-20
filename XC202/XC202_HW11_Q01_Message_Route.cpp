#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<vector<int>> q;
    q.push({1});
    vis[1] = 1;
    while(!q.empty()){
        vector<int> crt = q.front();
        q.pop();
        int i = crt.back();
//        for(int k: crt){
//            cout << k << " ";
//        }
//        cout << endl;
        if(i == n){
            cout << crt.size() << endl;
            for(int v: crt){
                cout << v << " ";
            }
            return 0;
        }
        for(int j: graph[i]){
            vector<int> copy = crt;
            if(vis[j] != 1){
                copy.push_back(j);
                q.push(copy);
                vis[j] = 1;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
/*
5 5
1 2
1 3
1 4
2 3
5 4

  2
 / \
1 - 3
 \
  4 -  5
 
 {{1, 2}, {3, 4}}
 {
 {},
 {2, 3, 4},
 {1, 3},
 {1, 2},
 {1, 5}
 {4}
 
 q =[{1}] + {1,2} + {1,3} + {1, 4} + {1, 4, 5}]
 
 
 
1 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 1
0 0 0 1 0

3
1 4 5

 10 20
8 9
6 7
9 10
7 9
3 4
5 8
6 8
1 2
5 7
8 10
2 3
1 4
7 8
5 6
6 9
1 3
4 5
3 6
3 5
7 10

*/