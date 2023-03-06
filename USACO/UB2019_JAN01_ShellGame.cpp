#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n, ans = 0;
    cin >> n;
    vector<vector<int>> change(n, vector<int>(3));
    for (int i = 0; i < n; i ++) {
        cin >> change[i][0] >> change[i][1] >> change[i][2];
    }
    for (int i = 1; i < 4; i ++) {
        int correct = 0;
        for (int j = 0, c = i; j < n; j ++) {
            int a = change[j][0], b = change[j][1];
            if (c == a) {
                c = b;
            } else if (c == b) {
                c = a;
            }
            if (c == change[j][2]) {
                correct ++;
            }
        }
        ans = max(ans, correct);
    }
    cout << ans << endl;
}

/*
3
1 2 1
3 2 1
1 3 1
*/