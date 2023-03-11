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
#include <cstring>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, K, ans = 0;
        cin >> n >> K;
        vector<string> matrix(n);
        for (int i = 0; i < n; i++) {
            cin >> matrix[i];
        }
        int dp[n][n][K + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n && matrix[0][j] == '.'; j++) {
            dp[0][j][K][0] = 1;
        }
        for (int i = 0; i < n && matrix[i][0] == '.'; i++) {
            dp[i][0][K][1] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 'H') {
                    continue;
                }
                for (int k = 0; k <= K; k++) {
                    dp[i][j][k][0] += dp[i][j - 1][k][0];
                    dp[i][j][k][1] += dp[i - 1][j][k][1];
                    if (k > 0) {
                        dp[i][j][k - 1][0] += dp[i][j - 1][k][1];
                        dp[i][j][k - 1][1] += dp[i - 1][j][k][0];
                    }
                }
            }
        }
        for (int k = 0; k <= K; k ++) {
            ans += dp[n - 1][n - 1][k][0] + dp[n - 1][n - 1][k][1];
        }
        cout << ans << endl;
    }
}

/*
7
3 1
...
...
...
3 2
...
...
...
3 3
...
...
...
3 3
...
.H.
...
3 2
.HH
HHH
HH.
3 3
.H.
H..
...
4 3
...H
.H..
....
H...


 */