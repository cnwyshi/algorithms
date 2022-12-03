// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, ans =0;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        int t = i;
        while(t > 0){
            int m = t % 10;
            if(m == x){
                ans++;
            }
            t = t/10;
        }
    }
    cout << ans;
}
