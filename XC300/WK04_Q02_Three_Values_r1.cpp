#include <bits/stdc++.h>
using namespace std;

// 181ms
int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i ++) {
        cin >> nums[i][0];
        nums[i][1] = i + 1;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1, k = n - 1; j < k; ) {
            int s = nums[i][0] + nums[j][0] + nums[k][0];
            if (s < x) {
                j ++;
            } else if (s > x) {
                k --;
            } else {
                cout << nums[i][1] << " " << nums[j][1] << " " << nums[k][1] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

/*
Sample Input:
4 8
2 7 5 1

Sample Output:
4 1 3
*/