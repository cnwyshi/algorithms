#include <vector>
#include <iostream>

using namespace std;

int f01knapsack(vector<int> &w, vector<int> &v, int m) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= m; j++) {
            // dp[i][j] = dp[i - 1][j];
            if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    return dp[n][m];
}

int f01knapsack_2(vector<int> &w, vector<int> &v, int m) {
    int n = w.size();
    vector<int> dp(m + 1), prev;
    for (int i = 1; i <= n; i++) {
        prev = dp;
        for (int j = 0; j <= m; j++) {
            if (w[i - 1] <= j) {
                dp[j] = max(dp[j], prev[j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    return dp[m];
}

int f01knapsack_3(vector<int> &w, vector<int> &v, int m) {
    int n = w.size();
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
        }
    }
    return dp[m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    // cout << f01knapsack(w, v, m) << endl;
    cout << f01knapsack_2(w, v, m) << endl;
}
/*
2 3
1 1
3 2

http://poj.org/problem?id=3624

Description

Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3,402) available charms. Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), a 'desirability' factor Di (1 ≤ Di ≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

Output

* Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints

Sample Input

4 6
1 4
2 6
3 12
2 7
Sample Output

23
 */