#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> height(n), add(n), taller(n), p(n);
        for (ll &i: height) cin >> i;
        for (ll &i: add) cin >> i;
        for (ll &i: taller) cin >> i;
        for (int i = 0; i < n; i++) {
            p[n - 1 - taller[i]] = i;
        }
        ll day = 0;
        for (int x = 0; x + 1 < n; x++) {
            int i = p[x], j = p[x + 1];
            // ll dh = (height[i] + add[i] * day) - (height[j] + add[j] * day), da = add[j] - add[i];;
            ll dh = height[i] - height[j], da = add[j] - add[i];;
            if (dh >= 0 && da > 0) {
//                if (da <= 0) {
//                    day = -1;
//                    break;
//                }
                // day += dh / da + 1;
                day = max(day, dh / da + 1);
            }
        }
        for (int x = 0; x + 1 < n; x++) {
            int i = p[x], j = p[x + 1];
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