#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void permutations(vector<int> &nums, vector<int> &visited, int j, int last, int &ans) {
    int n = nums.size();
    if (j == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (j == 0 || abs(i + 1 - last) > 1) {
                visited[i] = 1;
                // nums[j] = i + 1;
                permutations(nums, visited, j + 1, i + 1, ans);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n), visited(n);
    permutations(nums, visited, 0, -1, ans);
    cout << ans << endl;
}

/*
5
*/