#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n = 0, i = 0, j = 0, up = 1;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int v = 1; v <= n * n; v++) {
        matrix[i][j] = v;
        if (up == 1) {
            i--;
            j++;
            if (j >= n) {
                i += 2;
                j--;
                up = 0;
            }
            if (i < 0) {
                i++;
                up = 0;
            }
        } else {
            i++;
            j--;
            if (i >= n) {
                j += 2;
                i--;
                up = 1;
            }
            if (j < 0) {
                j++;
                up = 1;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            cout << matrix[k][l] << " ";
        }
        cout << endl;
    }
    return 0;
}