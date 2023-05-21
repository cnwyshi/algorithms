#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> mice(n);
    set<int> hole;
    for(int i = 0; i < n; ++i){
        cin >> mice[i];
    }
    for(int i = 0; i < m; ++i){
        int pos;
        cin >> pos;
        hole.insert(pos);
    }
    long long ans = 0;
    for(int i : mice){
        set<int>::iterator it= hole.lower_bound(i);
        it--;
        ans+= abs(i-*it);
        hole.erase(it);
    }
    cout << ans << '\n';
}
/*
3 5
6 7 10
1 2 5 8 9

3 5
6 7 10
1 2 5 7 8 9

7
*/