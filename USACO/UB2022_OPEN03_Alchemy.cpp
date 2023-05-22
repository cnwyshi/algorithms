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
using vi = vector<int>;

bool make(vi &count, vvi &recipies, int t) {
    if (count[t] > 0) {
        count[t]--;
        return true;
    }
    if (recipies[t].empty()) {
        return false;
    }
    for (int i: recipies[t]) {
        if (!make(count, recipies, i)) {
            return false;
        }
    }
    return true;
}

int main() {
    int ans = 0;
    int n;
    cin >> n;
    vi met(n);
    for (int i = 0; i < n; i++) {
        cin >> met[i];
    }
    int potions;
    cin >> potions;
    vvi rec(n);
    for (int i = 0; i < potions; i++) {
        int l, m;
        cin >> l >> m;
        for (int j = 0; j < m; j++) {
            int metal;
            cin >> metal;
            rec[l - 1].push_back(metal - 1);
        }
    }
    while (make(met, rec, n - 1)) {
        ans++;
    }
    cout << ans << endl;
}
/*
5
2 0 0 1 0
3
5 2 3 4
2 1 1
3 1 2
*/