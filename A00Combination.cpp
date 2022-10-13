//
// Created by genius on 10/1/22.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void combinations(int m, int n, vector<int> &a, vector<int> &vis, int j) {
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
    for (int i = 1; i <= m; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            a[j] = i;
            combinations(m, n, a, vis, j + 1);
            vis[i] = 0;
        }

    }
}


int main() {
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    vector<int> vis(m);
    combinations(m, n, a, vis, 0);
}