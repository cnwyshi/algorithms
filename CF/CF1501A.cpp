#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t -- > 0) {
        int n, prev = 0, ans = 0;
        cin >> n;
        vector<int> a(n), b(n), tm(n);
        for (int i = 0; i <n; i ++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i <n; i ++) {
            cin >> tm[i];
        }
        for (int i = 0; i < n; i ++) {
            ans += a[i] - prev + tm[i];
            if (i < n - 1) {
                ans = max(ans + (b[i] - a[i] + 1) / 2, b[i]);
            }
            prev = b[i];
        }
        cout << ans << endl;
    }
    return 0;
}

/*
2
2
2 4
10 12
0 2
5
1 4
7 8
9 10
13 15
19 20
1 2 3 4 5

*/