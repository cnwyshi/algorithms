#include <bits/stdc++.h>

using namespace std;
using ll = long long;
static const auto fastio = []() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int main() {
    freopen("C:\\code\\GoogleDrive\\XC300\\in-090202.txt", "r", stdin);
    // freopen("todo.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll mid = 997932, sum = 0, count = 1;
    for (int v: nums) {
        if (sum + v > mid) {
            count++;
            cout << sum << endl;
            sum = 0;
        }
        sum += v;
    }
    cout << count << endl;


    // find smallest available
//    ll lo = 0, hi = 1e18;
//    while (lo < hi) {
//        ll mid = (lo + hi) / 2, sum = 0, count = 1;
//        for (int v : nums) {
//            if (sum + v > mid) {
//                count ++;
//                sum = 0;
//            }
//            sum += v;
//        }
//        // count += sum > 0;
//        cout << lo << " " << hi << " " << count << endl;
//        if (count > m) {
//            lo = mid + 1;
//        } else {
//            hi = mid;
//        }
//    }
//    cout << lo << endl;
    return 0;
}

/*
6 3
4 2 4 5 1 1

样例输入：

5 3
4 2 4 5 1
样例输出：

6

 */