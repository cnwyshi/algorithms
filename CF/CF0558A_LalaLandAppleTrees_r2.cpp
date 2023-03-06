#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m = 0, ans = 0, i, j;
    cin >> n;
    vector<vector<int>> tree(n, vector<int>(2));
    for (i = 0; i < n; i ++) {
        cin >> tree[i][0] >> tree[i][1];
        m += tree[i][0] < 0;
    }
    sort(tree.begin(), tree.end());
    for (i = m - 1, j = m; i >= 0 && j < n; i --, j ++) {
        ans += tree[i][1] + tree[j][1];
    }
    if (i >= 0) {
        ans += tree[i][1];
    } else if (j < n) {
        ans += tree[j][1];
    }
    cout << ans << endl;
    return 0;
}


// https://codeforces.com/problemset/problem/558/A
// sort and iterate

/*
3
1 9
3 5
7 10
*/