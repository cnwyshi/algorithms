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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> barn(n);
    for (int i = 0; i < n; i++) {
        cin >> barn[i];
    }
    for (int i = 0; i < n; i++) {
        int v = 0;
        for (int j = 0; j < n; j++) {
            v += barn[(i + j) % n] * j;
        }
        ans = min(ans, v);
    }
    cout << ans << endl;
    return 0;
}

/*
5
4
7
8
6
4
*/