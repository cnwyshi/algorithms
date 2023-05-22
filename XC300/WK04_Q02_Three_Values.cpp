#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0];
        nums[i][1] = i;
    }
    sort(nums.begin(), nums.end());
    for (int k = 0; k < n; k++) {
        int i = k + 1;
        int j = n - 1;
        while (j > i) {
            int s = nums[j][0] + nums[i][0] + nums[k][0];
            if (s == t) {
                cout << nums[j][1] + 1 << " " << nums[i][1] + 1 << " " << nums[k][0] + 1 << endl;
                return 0;
            }
            if (s < t) {
                i++;
            }
            if (s > t) {
                j--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
/*
4 8
2 7 5 1


z
*/