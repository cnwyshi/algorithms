#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> intervals(m, vector<ll>(2));
    for (int i = 0; i < m; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    sort(intervals.begin(), intervals.end());
    ll INF = 2000000000LL, lo = 1, hi = 1LL * INF * INF, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2, p = -hi, count = 0;
        for (int i = 0; count < n && i < m; i++) {
            while (count < n && max(p + mid, intervals[i][0]) <= intervals[i][1]) {
                count++;
                p = max(p + mid, intervals[i][0]);
            }
        }
        // cout << lo << " " << hi << " " << n << endl;
        if (count >= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}

/*
5 3
0 2
4 7
9 9
 */