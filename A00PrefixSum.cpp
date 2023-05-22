#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> &matrix) {
    for (vector<int> &row: matrix) {
        for (int v: row) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2},
                                  {3, 4}};
    print(matrix);

    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = 0;
        }
    }
    print(prefix);
}

