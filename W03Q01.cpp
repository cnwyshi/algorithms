// Source: https:// usaco.guide/general/io

#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int> &nums, int k, int i, int sum) {
    int n = nums.size();
    if (i == n) {
        if (sum % k == 0) {
            for (int i = 0; i < n; i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int v = 1; v <= n; v++) {
        nums[i] = v;
        dfs(nums, k, i + 1, sum + v);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 1);
    dfs(nums, k, 0, 0);
    return 0;
}
/*
Sample Input:

3 8

Sample Output:

2 3 3

3 2 3

3 3 2
*/