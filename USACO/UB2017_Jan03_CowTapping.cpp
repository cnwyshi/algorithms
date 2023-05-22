#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

const char TIPPED = '0';

int flip(vector<vector<int>> &cows, int r, int c) {
    if (cows[r][c]) {
        for (int ri = 0; ri <= r; ri++) {
            for (int ci = 0; ci <= c; ci++) {
                cows[ri][ci] = !cows[ri][ci];
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> cows(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        string row;
        cin >> row;
        for (int c = 0; c < n; c++) {
            cows[r][c] = row[c] - '0';
        }
    }

    int x = n - 1, y = n - 1;
    int min_flips = 0;
    while (x >= 0 && y >= 0) {
        // Flip the rectangle with lower right corner at (x, y)
        min_flips += flip(cows, x, y);
        if (x != y) {
            // Also flip rectangle at (y, x) if it is different
            min_flips += flip(cows, y, x);
        }

        /*
         * Transition to the next cell, first going to the left and then
         * to the next row if the current row has finished.
         */
        if (x > 0) {
            x--;
        } else {
            y--;
            x = y;
        }
    }
    cout << min_flips << endl;
}