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
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int lo = 1, hi = n;
    while (lo < hi) {
        ll mid = (lo + hi) / 2, i = 0, last = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (; i < n; i++) {
            if (pq.size() == mid) {
                last = pq.top();
                pq.pop();
            }
            if (last + nums[i] > t) {
                break;
            }
            pq.push(last + nums[i]);
        }
        if (i < n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
    return 0;
}

/*
SAMPLE INPUT:
5 8
4
7
8
6
4

SAMPLE OUTPUT:

4

 */