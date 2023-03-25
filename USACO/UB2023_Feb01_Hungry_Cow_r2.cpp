#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> d(n + 1), b(n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> d[i] >> b[i];
    }
    d[n] = t + 1;

    ll remaining = 0, total = 0, prev = 0;
    for (int i = 0; i <= n; i ++) {
        total += b[i];
        remaining -= d[i] - prev;
        remaining = max(remaining, 0LL) + b[i];
        prev = d[i];
    }

    cout << total - remaining << endl;
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