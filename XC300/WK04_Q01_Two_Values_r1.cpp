#include <bits/stdc++.h>

using namespace std;

// 526ms
int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0];
        nums[i][1] = i;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0, j = n - 1; i < j;) {
        int s = nums[i][0] + nums[j][0];
        if (s < x) {
            i++;
        } else if (s > x) {
            j--;
        } else {
            cout << (nums[i][1] + 1) << " " << (nums[j][1] + 1) << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

// 392ms
int main_map() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    map<int, int> index;
    for (int i = 0; i < n; i++) {
        int a = nums[i], b = x - a;
        if (index.find(b) != index.end()) {
            cout << (index[b] + 1) << " " << (i + 1) << endl;
            return 0;
        }
        index[a] = i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
/*
样例输入：
4 8
2 7 5 1


样例输出：
2 4
*/