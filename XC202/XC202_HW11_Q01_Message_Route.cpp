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
    vector<int> parent(n+1);
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int i = q.front();
        q.pop();
//        for(int k: crt){
//            cout << k << " ";
//        }
//        cout << endl;
        if(i == n){
            stack<int> st;
            for(int p = n; p != -1; p = parent[p]){
                st.push(p);
            }
            cout << st.size() << endl;
            while(!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
            return 0;
        }
        for(int j: graph[i]){
            if(vis[j] != 1){
                q.push(j);
                vis[j] = 1;
                parent[j] = i;
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