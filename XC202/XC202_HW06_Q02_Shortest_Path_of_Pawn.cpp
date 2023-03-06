// Source: https://usaco.guide/general/io

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

int main() {
    int n, sx, sy, ex, ey, ans = 0;
    cin >> n >> sx >> sy >> ex >> ey;
    int dx = abs(ex-sx);
    int dy = abs(ey-sy);
    if(sx == ex && ey == sy){
        cout << 0 << endl;
        return 0;
    }
    if(dx % 2 == 0){
        ans += dx/2;
    }
    if(dx % 2 != 0){
        ans += dx/2 + 1;
    }
    if(dy % 2 == 0){
        ans += dy/2;
    }
    if(dy % 2 != 0){
        ans += dy/2 + 1;
    }
    cout << ans << endl;
}
