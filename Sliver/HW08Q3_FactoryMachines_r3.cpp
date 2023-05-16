#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // freopen("C:\\Users\\flame\\Downloads\\sample.in", "r", stdin);
    // freopen("C:\\Users\\flame\\Downloads\\080302.txt", "r", stdin);

    ll n, t;
    cin >> n >> t;
    // cout << n << " " << t << endl;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    // find first available =
    ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo + hi) / 2, sum = 0;
        for (int i = 0; i < n && sum < t; i ++) {
            sum += mid / m[i];
        }
        // printf("lo = %lld, hi = %lld, mid = %lld, sum = %lld, t = %lld\n", lo, hi, mid, sum, t);
        if (sum < t) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << "\n";
}

/*
1 1000000000
1000000000

hi * 2^10^5
5 * 10^13
10 10
6 5 1 2 1 5 10 4 6 6
    4 2 4
1 1       1 2  1 1 1


Input:
3 7
3 2 5

Output:
8


 */