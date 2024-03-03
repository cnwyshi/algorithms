#include<bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> root, size;
    int count, max_value = 1;
public:
    DSU(int n) {
        count = n;
        root.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            root[i] = i;
        }
    }
    int find(int i) {
        return root[i] = (root[i] == i ? i : find(root[i]));
    }
    bool union_(int a, int b) {
        int ra = find(a), rb = find(b);
        if(ra == rb){
            return false;
        }
        root[ra] = rb;
        size[rb] += size[ra];
        max_value = max(max_value, size[rb]);
        count--;
        return true;
    }
};
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }
    long long ans = 0;
    DSU dsu(n);
    while(!pq.empty()){
        vector<int> crt = pq.top();
        pq.pop();
        int a = crt[1], b = crt[2], c = crt[0];
        if(dsu.union_(a, b)){
            ans += c;
        }
    }
    cout << ans << endl;
}
/*
5 7
1 2 17
1 4 5
1 5 23
2 3 30
2 4 10
3 4 24
3 5 7
 */