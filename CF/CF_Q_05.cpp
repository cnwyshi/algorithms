//
// Created by genius on 12/26/2022.
//

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

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