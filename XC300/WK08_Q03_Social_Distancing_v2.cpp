#include <bits/stdc++.h>

using namespace std;

int calc(vector<vector<long long>> &grass, long long d) {
    int m = grass.size(), count = 1;
    long long last = -1e18;
    for (int i = 0; i < m; i++) {
        long long next = max(last + d, grass[i][0]);
//        cout << i << " " << last << " " << next << endl;
        for (; next <= grass[i][1];) {
            count++;
            last = next;
            next = max(last + d, grass[i][0]);
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("/Users/genius/Downloads/123456.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> grass(m, vector<long long>(2));
    for (int i = 0; i < m; i++) {
        cin >> grass[i][0] >> grass[i][1];
    }
    sort(grass.begin(), grass.end());
    long long lo = 0, hi = 1e18, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
//        cout << lo << " " << hi << " " << mid << " " << calc(grass, mid) << endl;
        if (calc(grass, mid) >= n) {
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


largest possible] (smallest impossible
 */