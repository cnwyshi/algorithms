#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& nums) {
    for (int v : nums) {
        cout << v << " ";
    }
    cout << endl;
}

// 53ms
int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> nums(n), left(n), right(n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    for (int i = 0, j = 0; i < n; i ++) {
        for ( ; j < n && nums[j] - nums[i] <= k; j ++) {
        }
        left[i] = j - i;
    }

    for (int i = n - 1; i >= 0; i--) {
        right[i] = max(right[i + 1], left[i]);
    }

    for (int i = 0; i < n; i ++) {
        ans = max(ans, left[i] + right[i + left[i]]);
    }
    cout << ans << endl;
    return 0;
}

/*
SAMPLE INPUT:
7 3
10
5
1
12
9
5
14


SAMPLE OUTPUT:
5
*/