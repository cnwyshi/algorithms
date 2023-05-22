#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int lo = 0, hi = n;
    while (lo < hi) {

    }
    vector<int>::iterator it = std::lower_bound(nums.begin(), nums.end(), t);
    cout << (*it == t ? it - nums.begin() + 1 : 0) << endl;
    return 0;
}

/*
7 4
1 2 4 4 5 7 9


 */