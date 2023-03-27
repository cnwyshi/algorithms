#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, t, r = 0, ans = 0;
    cin >> n >> t;
    vector<ll> d(n + 2), b(n + 2);
    for (int i = 1; i <= n; i ++) {
        cin >> d[i] >> b[i];
    }
    d[n + 1] = t + 1;

    for (int i = 1; i < n + 2; i ++) {
        ll used = min(r, d[i] - d[i - 1]);
        r = r - used + b[i];
        ans += used;
    }

    cout << ans << endl;
    return 0;
}

/**
2 5
1 2
5 10
 i = 0, total = 2, r = 1 - 0 = 1, p = 1, r
 i = 1

SAMPLE INPUT:
1 5
1 2
SAMPLE OUTPUT:
2
Two haybales arrive on the morning of day 1. Bessie eats one haybale for dinner on day 1 and another haybale on day 2. On days 3…5, there are no more haybales for Bessie to eat. In total, Bessie eats 2 haybales during the first 5 days.
SAMPLE INPUT:
2 5
1 2
5 10
SAMPLE OUTPUT:
3
Two haybales arrive on the morning of day 1. Bessie eats one haybale on days 1 and 2. There are no haybales for Bessie to eat on days 3 and 4. On the morning of day 5, 10 haybales arrive. Bessie eats one haybale for dinner on day 5. In total, Bessie eats 3 haybales during the first 5 days.
SAMPLE INPUT:
2 5
1 10
5 10
SAMPLE OUTPUT:
5
*/