#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// "PSH", 012
void dfs(vector<int> signs, int k, int i, int s, int sum, int& ans) {
    if (i == signs.size()) {
        ans = max(ans, sum);
        return;
    }
    if ((s - signs[i] + 3) % 3 == 1) {
        dfs(signs, k, i + 1, s, sum + 1, ans);
    } else if (k > 0) {
        for (int j = 1; j < 3; j ++) {
            int t = (s + j) % 3;
            if ((t - signs[i] + 3) % 3 == 1) {
                dfs(signs, k - 1, i + 1, t, sum + 1, ans);
            } else {
                dfs(signs, k - 1, i + 1, t, sum, ans);
            }
        }
    }
}

int main() {
    int n = 0, k = 0, ans = 0;
    cin >> n >> k;
    vector<int> signs(n);
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        signs[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    for (int s = 0; s < 3; s ++) {
        dfs(signs, k, 0, s, 0, ans);
    }
    cout << ans << endl;
    return 0;
}

/*
5 1
P
P
H
P
S
*/