#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    int t;
    cin >> t;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i < n; i++) {
        nums[i] = nums[i - 1] + nums[i];
    }
    map<long long, int> sums;
    sums[0]++;
    for (int i = 0; i < n; i++) {
        if (sums.find(nums[i] - t) != sums.end()) {
            ans += sums[nums[i] - t];
        }
        sums[nums[i]]++;
    }
    cout << ans << endl;
    return 0;
}
/*
5 7
2 -1 3 5 -2
*/