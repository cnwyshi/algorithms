#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (hi + lo) / 2;
        if (nums[mid] >= t) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << (nums[lo] == t ? lo + 1 : 0) << '\n';
}

/*
Sample Input:
7 4
1 2 4 4 5 7 9
Sample Output:
3

lo = 0; hi = 6; mid = 3; nums[mid] = 4 >= 4; hi = mid;
lo = 0; hi = 3; mid = 1; nums[mid] = 2 < 4; low = mid+1;
lo = 2; hi = 3; mid = 2; nums[mid] = 4 >= 4; hi = mid;
lo = 2; hi = 2;

Sample Input:
3 2
1 3 5
Sample Output:
0

lo = 0; hi = 2; mid = 1; nums[mid] = 3; 3 >= 2; hi = mid;
lo = 0; hi = 1; mid = 0; nums[mid] = 1; 1 < 2; low = mid+1;
lo = 1; hi = 1;
*/