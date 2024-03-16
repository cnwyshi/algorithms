#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, t;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s >> t;
}
/*
7  9
1  2  1
1  3  2
2  3  3
4  5  1
4  7  3
5  6  2
6  7  4
4  6  5
5  7  8

9

1---(1)---2
|        /
(2)    (3)
|      /
3----+


 */