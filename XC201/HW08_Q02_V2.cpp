#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void permutations(vector<vector<int>> &cows, vector<int> &nums, vector<int> &visited, int j, int x, int y, int &ans) {
    int n = nums.size();
    if (j == n) {
        if (x == 0 || y == 0) {
            ans++;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && (cows[i][0] == x || cows[i][1] == y)) {
            visited[i] = 1;
            nums[j] = i;
            permutations(cows, nums, visited, j + 1, cows[i][0], cows[i][1], ans);
            visited[i] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cows(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> cows[i][j];
        }
    }

    int ans = 0;
    vector<int> nums(n);
    vector<int> visited(n);
    permutations(cows, nums, visited, 0, 0, 0, ans);
    cout << ans << endl;
}
/*
4
0 1
2 1
2 0
2 -5

vector<vector<char>> maze (n, vector<char> (m));
*/