#include <iostream>
#include <vector>

using namespace std;

void permutations(int m, vector<int> &nums, int j, vector<int> &visited) {
    int n = nums.size();
    if (j == n) {
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        if (visited[i] != 0) {
            continue;
        }
        visited[i] = 1;
        nums[j] = i;
        permutations(m, nums, j + 1, visited);
        visited[i] = 0;
    }
}


int main() {
    int m, n;
    cin >> m >> n;
    vector<int> visited(m);
    vector<int> nums(n);
    permutations(m, nums, 0, visited);
}