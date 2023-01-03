//
// Created by genius on 12/26/2022.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for(int i = 0; i < t; i ++){
        long long n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        long long bl(sx-1), br(m - sy);
        long long u = bl < br ? bl : br;
        bl = n - sx;
        br = sy-1;
        long long v = bl < br ? bl : br;
        bool res = (u > d) || v > d;
        cout << res ? (n+m-2) : -1;
    }
}