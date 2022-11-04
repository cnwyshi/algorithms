#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void combinations(int m, int n, vector<int> &a, vector<int> &visited, int j) {
    if (j == n) {
        bool match = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] >= a[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < m; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            a[j] = i + 1;
            combinations(m, n, a, visited, j + 1);
            visited[i] = 0;
        }
    }
}


int main() {
    int n, m;
    cin >> m >> n;
    vector<int> nums(n);
    vector<int> visited(m);
    combinations(m, n, nums, visited, 0);
}