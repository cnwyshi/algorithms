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
        ll days = 0;
        for (int x = 0; x + 1 < n; x++) {
            int small_idx = p[x], big_idx = p[x + 1];
            // ll h_diff = (height[big_idx] + add[big_idx] * days) - (height[small_idx] + add[small_idx] * days);
            ll h_diff = (height[small_idx] + add[small_idx] * days) - (height[big_idx] + add[big_idx] * days);
            if (h_diff >= 0) {
                ll a_diff = add[big_idx] - add[small_idx];
                if (a_diff <= 0) {
                    days = -1;
                    break;
                }
                days += ceil_div(h_diff + 1, a_diff);
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            ll small_days = height[p[i]] + add[p[i]] * days;
            ll big_days = height[p[i + 1]] + add[p[i + 1]] * days;
            if (small_days >= big_days) {
                days = -1;
                break;
            }
        }
        cout << days << "\n";
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
*/