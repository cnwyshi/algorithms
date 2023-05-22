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

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> diff(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> diff[i][j];
        }
    }
    vector<int> ans(n);
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = ans[i + 1] + diff[i][i + 1];
        int mx = INT_MIN, mn = INT_MAX, match = 1;
        for (int j = i; j < n && match; j++) {
            mx = max(mx, ans[j]);
            mn = min(mn, ans[j]);
            match &= mx - mn == diff[i][j];
        }
        if (!match) {
            ans[i] = ans[i + 1] - diff[i][i + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i < n - 1 ? " " : "");
    }
    return 0;
}

/*
4
2 1 4 5
1 2
2 3
2 4

1(2)-2(1)-3(4)
      \
      4(5)
1+2+4+5=12 / 4 = 3

*/