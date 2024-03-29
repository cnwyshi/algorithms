#include <bits/stdc++.h>

using namespace std;

//void print(vector<vector<int>>& matrix){
//    int m = matrix.size(), n = matrix[0].size();
//    for(int i = 0; i < m; i++){
//        for(int j = 0; j < n; j++){
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            forest[i][j] = s[j] == '*';
        }
    }
    vector<vector<int>> ps(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + forest[i][j];
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        cout << ps[x2 + 1][y2 + 1] - ps[x2 + 1][y1] - ps[x1][y2 + 1] + ps[x1][y1] << '\n';
    }
    return 0;
}
/*
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2

0 1 0 0
1 0 1 1
1 1 0 0
1 1 1 1

0 0 0 0 0
0 0 1 1 1
0 1 2 3 4
0 2 4 5 6
0 3 6 8 10

1 1 2 3
2 0 2 0
0 0 1 1

A-----B---C
|     |   |
D-----E---F y1
|     |   |
G-----H---I y2
      x1  x2
EFHI = I - F - H + E
= ps[x2+1][y2+1] - ps[x2+1][y2] - ps[x1][y2+1] + ps[x1+1][y1+1]
E = x1, y1
I = x2, y2
H = x1, y2
F = x2, y1

6 -
3 1 2
*/