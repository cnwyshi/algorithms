#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>


using namespace std;

int main() {
    int t, n, tc, tm, ans = INT_MAX;
    cin >> t;
    while (t--) {
        cin >> n >> tc >> tm;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        // for (int i = 0, j = 1000; i < )

        for (int x = 1; x <= tc; x ++) {
            for (int y = 1; y <= tm; y ++) {
                bool success = true;
                for (int i = 0; i < n; i ++) {
                    if (x * a[i] + y * b[i] > c[i]) {
                        success = false;
                        break;
                    }
                }
                if (success) {
                    // cout << x << " " << y << " " << tm + tc - x - y << endl;
                    ans = min(ans, tm + tc - x - y);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
SAMPLE INPUT:
2

3 7 9
4 3 18
2 4 19
1 1 6

5 7 3
5 9 45
5 2 31
6 4 28
4 1 8
5 2 22

SAMPLE OUTPUT:
11
6

5 7 3
1 4

5 9 45
5 2 31
6 4 28
4 1 8
5 2 22
 */