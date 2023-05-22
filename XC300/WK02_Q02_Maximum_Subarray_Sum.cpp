#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    long long ans = 0, temp = 0;
    bool change = false;
    for (int i = 0; i < nums.size(); i++) {
        int copy = ans;
        temp += nums[i];
        if (temp < 0)
            temp = 0;
        ans = max(ans, temp);
        if (ans != copy) {
            change = true;
        }
    }
    if (change) {
        cout << ans << endl;
    } else if (!change) {
        int f = INT_MIN;
        for (int i: nums) {
            f = max(i, f);
        }
        cout << f << endl;
    }
}