#include <iostream>
#include <vector>

using namespace std;

void permutations(int m, vector<int>& a, int j, vector<int>& vis) {
    int n = a.size();
    if (j == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        if (vis[i] != 0) {
            continue;
        }
        vis[i] = 1;
        a[j] = i;
        permutations(m, a, j + 1, vis);
        vis[i] = 0;
    }
}


int main() {
    int m, n;
    cin >> m >> n;
    vector<int> visited(m);
    vector<int> nums(n);
    permutations(m, nums, 0, visited);
}