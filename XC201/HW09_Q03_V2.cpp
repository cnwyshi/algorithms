#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 100005;
int n, k, a[maxn], f[maxn][25][5];

bool win(int a, int b) {
    return (a + 3 - b) % 3 == 1;
}

int dfs(int i, int k, int c) {
    if (k == -1)
        return 0;
    if (i == n - 1)
        return win(c, a[i]);
    if (f[i][k][c])
        return f[i][k][c];
    int ans = 0;
    if ((c + 3 - a[i]) % 3 == 1) {
        ans = max(ans, dfs(i + 1, k, c) + 1);
    } else {
        ans = max(ans, dfs(i + 1, k, c));
        if (k > 0) {
            ans = max(ans, dfs(i + 1, k - 1, (a[i] + 1) % 3) + 1);
        }
    }
//    for (int j = 0; j < 3; ++j) {
//        if (j == c) {
//            ans = max(ans, dfs(i + 1, k, j) + win(j, a[i]));
//        } else {
//            ans = max(ans, dfs(i + 1, k - 1, j) + (k > 0 ? win(j, a[i]) : 0));
//        }
//        // ans = max(ans, dfs(i + 1, k - (j != c), j) + (k - (j != c) >= 0 ? win(j, a[i]) : 0));
//    }
    return f[i][k][c] = ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        a[i] = c == 'P' ? 0 : (c == 'S' ? 1 : 2);
    }
    cout << max(dfs(0, k, 0), max(dfs(0, k, 1), dfs(0, k, 2))) << endl;
    return 0;
}