#include <bits/stdc++.h>

using namespace std;

long long calc(vector<int> &nums, long long sum) {
    long long temp = 0, count = 1;
    for (int i = 0; i < nums.size(); i++) {
        temp += nums[i];
        if (temp > sum) {
            temp = nums[i];
            count++;
        }
//        cout << i << " " << temp << " " << n << endl;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, mx;
    long long sum = 0;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        mx = max(mx, nums[i]);
    }
    long long lo = mx, hi = sum;
    while (lo < hi) {
        long long mid = (lo + hi) / 2, count = 0, temp = 0;
//        cout << lo << " " << hi << " " << mid << " " << calc(nums, mid) << endl;
        if (calc(nums, mid) > k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
//    cout << n(nums, 5) << endl;
//    cout << n(nums, 6) << endl;
//    cout << n(nums, 7) << endl;
//    cout << n(nums, 10) << endl;

}
/*
Input:
5 3
4 2 4 5 1

Output:
6

4 2 4 5 1
expected_sum = 5, n = 5
expected_sum = 6, n = 3
expected_sum = 7, n = 3
expected_sum = 10, n = 2
*/