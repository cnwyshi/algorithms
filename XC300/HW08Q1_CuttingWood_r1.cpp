#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const auto fastio = []() { std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    // find highest available = find first unavailable - 1
    int lo = 0, hi = INT_MAX;
    while (lo < hi) {
        ll mid = (lo + hi) / 2, sum = 0;
        for (int v : nums) {
            sum += max(v - mid, 0LL);
        }
        if (sum >= m) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo - 1 << endl;
    return 0;
}

/*
Sample Input:
5 20
4 42 40 26 46


Sample Output:
36

 */