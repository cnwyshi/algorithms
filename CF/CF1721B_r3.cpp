#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t, m, n, sx, sy, d, ans = 0;
    int D[] = {0, 1, 0, -1, 0};
    cin >> t;
    while (t-- > 0) {
        cin >> m >> n >> sx >> sy >> d;
        sx--, sy--;
        if (sx - d > 0 && sy + d < n - 1
            || sy - d < 0 && sx + d < m - 1) {
            cout << (m + n - 2) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

/*
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1


*/