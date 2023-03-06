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
    int n;
    string s;
    cin >> n >> s;
    vector<int> e(n);
    for (int i = 0; i < n; e[i++]--) {
        cin >> e[i];
    }
    int lg = s.find("G"), lh = s.find("H"), rg = s.rfind("G"), rh = s.rfind("H");
    int gg = 0, hh = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            if (e[i] >= lh && i < lh && e[lh] >= rh) {
                ans ++;
                if (i == lg) {
                    gg = 1;
                }
            }
        }
        if (s[i] == 'H') {
            if (e[i] >= lg && i < lg && e[lg] >= rg) {
                ans++;
                if (i == lh) {
                    hh = 1;
                }
            }
        }
    }
    if (e[lg] >= rg && e[lh] >= rh && !gg && !hh) {
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
*/