#include <bits/stdc++.h>
using namespace std;

int diff[1000][1000];
int barn[1001][1001];

void print(int matrix[][1001], int m, int n) {
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
   x1            x2
  +---------------+---------------+
y1|*              |               |
  |               |               |
y2|              *|               |
  +---------------+---------------+
  |               |               |
  |               |               |
  |               |               |
  +---------------+---------------+
*/
int main() {
    int n, k, x1, y1, x2, y2, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 --, y1 --, x2 --, y2 --;
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
            printf("%d %d %d %d %d\n", i, x1, y1, x2, y2);
        }
        diff[x1][y1] ++;
        diff[x1][y2] --;
        diff[x2][y1] --;
        diff[x2][y2] ++;
    }
    // print(prefix, 10, 10);
    cout << __LINE__ << endl;
    for (int i = 0; i < 1000; i ++) {
        for (int j = 0; j < 1000; j ++) {
            // barn[i+1][j+1] = barn[i][j + 1] + barn[i + 1][j] - barn[i][j] + diff[i][j];
            cout << i + 1 << " " << j + 1 << endl;
            if (barn[i + 1][j + 1] == k) {
                ans ++;
            }
        }
    }
    // print(barn, 1001, 1001);

    cout << ans << endl;
    return 0;
}



/*

3 2
1 1 5 5
4 4 7 6
3 3 8 7


0 0 4 4
3 3 6 5
2 2 7 6

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

1 1 1 1 1 0 0
1 1 1 1 1 0 0
1 1 1 1 1 0 0
1 1 1 2 2 1 0
1 1 1 2 2 1 0
0 0 0 1 1 1 0
0 0 0 1 1 1 0
0 0 0 0 0 0 0

1 1 1 1 1 0 0
1 1 1 1 1 0 0
1 1 2 2 2 1 1
1 1 2 3 3 2 1
1 1 2 3 3 2 1
0 0 1 2 2 2 1
0 0 0 1 1 1 0
0 0 0 0 0 0 0
*/