#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> height(n), add(n), taller(n), sorted(n);
        for (ll &v: height) cin >> v;
        for (ll &v: add) cin >> v;
        for (ll &v: taller) cin >> v;
        for (int i = 0; i < n; i++) {
            sorted[n - 1 - taller[i]] = i;
        }
        ll day = 0;
        for (int x = 0; x + 1 < n; x++) {
            int i = sorted[x], j = sorted[x + 1];
            ll dh = height[i] - height[j], da = add[j] - add[i];;
            if (dh > 0 && da > 0) {
                // if (da != 0) {
                day = max(day, dh / da + 1);
            }
        }
        for (int x = 0; x + 1 < n; x++) {
            int i = sorted[x], j = sorted[x + 1];
            if (height[i] + add[i] * day >= height[j] + add[j] * day) {
                day = -1;
                break;
            }
        }
        cout << day << "\n";
    }

}

/*
1
2
7 3
8 10
1 0

1
3
3 8 5
3 1 3
2 1 0

2
5
7 4 1 10 12
3 4 5 2 1
2 1 0 3 4
5
4 10 12 7 1
3 1 1 4 5
2 4 3 1 0
*/