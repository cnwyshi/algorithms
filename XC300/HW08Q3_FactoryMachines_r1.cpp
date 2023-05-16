#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    // find first available
    ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo + hi) / 2, sum = 0;
        for (int v : m) {
            sum += mid / v;
        }
        if (sum < t) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << "\n";
}

/*
Input:
3 7
3 2 5

Output:
8


 */