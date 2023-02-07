#include <bits/stdc++.h>
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
    for (int i = 0; i < 3; i ++) {
        int correct = 0;
        vector<int> shell(3);
        shell[i] = 1;
        for (int j = 0; j < n; j ++) {
            int a = change[j][0], b = change[j][1], g = change[j][2], t = shell[a];
            shell[a] = shell[b];
            shell[b] = t;
            if (shell[g] == 1) {
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