#include <iostream>
#include <vector>

using namespace std;

/*
(0, 1), (2, 1), (2, 0), (2, -5)
*/
void permutations(vector<vector<int>>& cows, vector<int>& nums, vector<int>& visited, int j, int& ans) {
    int n = nums.size();
    if (j == n) {
//        for (int i = 0; i < n; i++) {
//            cout << nums[i] << " ";
//        }
//        cout << endl;
        // 0 3 2 1
        // cows[2][0] == cows[0][0]
        bool match = true;
        for(int i = 1; i<n; i++){
            int p = nums[i - 1], c = nums[i];
            if(cows[p][0] != cows[c][0] && cows[p][1] != cows[c][1]){
                match = false;
                break;
            }
        }
        int f = nums[0], c = nums[n - 1];
        if (cows[f][0] != 0 && cows[f][1] != 0) {
            match = false;
        }
        if (cows[c][0] != 0 && cows[c][1] != 0) {
            match = false;
        }
        if( match){
            ans ++;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0) {
            continue;
        }
        visited[i] = 1;
        nums[j] = i;
        permutations(cows, nums, visited, j + 1, ans);
        visited[i] = 0;
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
    permutations(cows, nums, visited, 0, ans);

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