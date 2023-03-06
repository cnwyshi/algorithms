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

signed main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    vector<int> e(n);
    for (int i = 0; i < n; e[i++]--) {
        cin >> e[i];
    }
    int fg = s.find("G"), fh = s.find("H"), lg = s.rfind("G"), lh = s.rfind("H");
    if (e[fg] >= lg) {                              // HHGGGH
        for (int i = fh; i < fg; i ++) {
            if (s[i] == 'H' && e[i] >= fg) {
                ans ++;
            }
        }
    }
    if (e[fh] >= lh) {                              // GGHHHG
        for (int i = fg; i < fh; i ++) {
            if (s[i] == 'G' && e[i] >= fh) {
                ans ++;
            }
        }
    }
    if (e[fg] >= lg && e[fh] >= lh && (e[fg] < fh || e[fh] < fg)) {     // GGGHHH, HHHGGG
        ans++;
    }
    cout << ans;
}


// https://www.acwing.com/file_system/file/content/whole/index/content/7970987/
/*
4
GHHG
2 4 3 4


SAMPLE OUTPUT:
1

SAMPLE INPUT:
3
GGH
2 3 3

GG
GH
H
SAMPLE OUTPUT:
2

4
GHGH
4 4 4 4
1

GHGH
HGH
GH
H

*/