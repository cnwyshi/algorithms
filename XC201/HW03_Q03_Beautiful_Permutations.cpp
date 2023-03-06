#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void permutations(vector<int> &nums, vector<int> &visited, int j, int &ans) {
    int n = nums.size();
    if (j == n) {
        bool match = true;
        // for(int i = 0; i < n; i++){
        // cout << nums[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= 1) {
                match = false;
                break;
            }
        }
        if (match) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            nums[j] = i + 1;
            permutations(nums, visited, j + 1, ans);
            visited[i] = 0;
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> visited(n);

    int ans = 0;
    permutations(nums, visited, 0, ans);
    cout << ans << endl;
}

/*
5
*/