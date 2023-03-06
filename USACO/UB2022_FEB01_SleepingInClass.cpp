#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        vector<int> v(n);
        int sum = 0, mx = 0;
        for (int i = 0; i < n; i ++) {
            cin >> v[i];
            sum += v[i];
            mx = max(mx, v[i]);
        }
        if (mx == 0) {
            cout << 0 << endl;
            continue;
        }
        for (int t = mx; t <= sum; t ++) {
            if (sum % t == 0) {
                int i = 0; // , c = 0;
                for (int s = 0; i < n; i ++) {
                    if (s + v[i] < t) {
                        s += v[i];
                        // c ++;
                    } else if (s + v[i] == t) {
                        s = 0;
                    } else {
                        break;
                    }
                }
                if (i == n) {
                    cout << n - sum / t << endl;
                    break;
                }
            }
        }
    }
}

/*
3
6
1 2 3 1 1 1
3
2 2 3
5
0 0 0 0 0

*/
