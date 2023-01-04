#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> matrix(6);
    for (int i = 0; i < 6; i ++) {
        cin >> matrix[i];
    }
    int g = 0, y = 0;
    vector<int> cc(128), cg(128);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            if (matrix[i][j] == matrix[i + 3][j]) {
                g ++;
            } else {
                cc[matrix[i][j]] ++;
                cg[matrix[i + 3][j]] ++;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; c ++) {
        y += min(cc[c], cg[c]);
    }
    cout << g << endl << y << endl;
}