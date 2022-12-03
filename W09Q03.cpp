#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 1<=n<=100000,0<=k<=20
bool visited[21][100000][3];

// "PSH", 012
void dfs(vector<int> signs, int k, int i, int s, int sum, int& ans) {
    if (i == signs.size()) {
        ans = max(ans, sum);
        return;
    }

    if (visited[k][i][s]) {
         return;
    }
    visited[k][i][s] = true;

    if ((s - signs[i] + 3) % 3 == 1) {
        dfs(signs, k, i + 1, s, sum + 1, ans);
    } else if (k > 0) {
        dfs(signs, k, i + 1, s, sum, ans);
        dfs(signs, k - 1, i + 1, (signs[i] + 1) % 3, sum + 1, ans);
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