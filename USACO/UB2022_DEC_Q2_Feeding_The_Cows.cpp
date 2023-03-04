#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k, as = 0;
        cin >> n >> k;
        string s, ans(n, '.');
        cin >> s;
        for(char c ='G'; c <='H'; c++){
            for(int i = 0, last = -k - 1; i < n; i++){
                if(s[i] == c){
                    if(abs(i-last) > k){
                        last = min(i+k, n-1);
                        while(ans[last]!='.'){
                            last--;
                        }
                        ans[last] = c;
                        as++;
                    }
                }
            }
        }
        cout << as << endl << ans << endl;
    }
}
/*
6
5 0
GHHGG
5 1
GHHGG
5 2
GHHGG
5 3
GHHGG
5 4
GHHGG
2 1
GH
*/