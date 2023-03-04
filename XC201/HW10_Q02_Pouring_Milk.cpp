//
// Created by genius on 11/14/22.
//

#include <iostream>

using namespace std;
int a;
int b;
int c;
int matrix[21][21] = {0};

void dfs(int i, int k) {
    if (matrix[i][k])
        return;
    matrix[i][k] = 1;

    if (i >= b - k)
        dfs(i - b + k, b);
    else dfs(0, i + k);

    if (k >= a - i)
        dfs(a, k - a + i);
    else dfs(i + k, 0);

    int j = c - i - k;
    if (j >= a - i)
        dfs(a, k);
    else dfs(i + j, k);

    if (j >= b - k)
        dfs(i, b);
    else dfs(i, k + j);

    dfs(0, k);

    dfs(i, 0);
}

int main() {
    cin >> a >> b >> c;
    dfs(0, 0);
    for (int v = 20; v >= 0; v--)
        if (matrix[0][v]) {
            if (v == 0) {
                cout << c << endl;
            } else
                cout << c - v << ' ';
        }
}
