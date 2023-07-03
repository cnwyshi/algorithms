#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        cin >> cnt[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        int x = cnt[a], y = cnt[b];
        int l = x, m = y;
        if(y == a){
            cnt[b] = x;
            cnt[a] = m;
        }
        if(x == b){
            cnt[b] = x;
            cnt[a] = m;
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i] == i){
            count ++;
        }
    }
    cout << count << endl;
}