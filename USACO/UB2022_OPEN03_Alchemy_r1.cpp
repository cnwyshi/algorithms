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
using vvi = vector<vector<int>>;

bool make(vector<int> &count, vvi &recipe, int t) {
    if (count[t]-- > 0) {
        return true;
    } else if (recipe[t].empty()) {
        return false;
    }
    for (int i: recipe[t]) {
        if (!make(count, recipe, i)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k, t, m, r, ans = 0;
    cin >> n;
    vector<int> count(n);
    for (int i = 0; i < n; i++) {
        cin >> count[i];
    }
    cin >> k;
    vvi recipe(n);
    for (int i = 0; i < k; i++) {
        cin >> t >> m;
        recipe[--t].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> r;
            recipe[t][j] = r - 1;
        }
    }
    while (make(count, recipe, n - 1)) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}

/*
5
2 0 0 1 0
3
5 2 3 4
2 1 1
3 1 2

*/