#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t, m, n, sx, sy, d, ans = 0;
    int D[] = { 0, 1, 0, -1, 0 };
    cin >> t;
    while (t -- > 0) {
        int ans = m * n;
        cin >> m >> n >> sx >> sy >> d;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (abs(i - sx) + abs(j - sy) > d) {
                    ans = min(ans, i + j + m - 1 - i + n - 1 - j);
                }
            }
        }
        cout << (ans == m * n ? -1 : ans) << endl;

    }
    return 0;
}

/*
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1


*/