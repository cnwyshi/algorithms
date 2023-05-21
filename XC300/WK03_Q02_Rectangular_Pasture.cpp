#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // cout << matrix[i][j] << " ";
        }
        // cout << endl;
    }
}
/*
        x1      x2
A------B----------C
|      |          |
|      |          |
D------E----------F
|      |          | y1
|      |          |
|      |          | y2
G------H----------I


rsum(x1, y1, x2, y2) = EFIH = ACIG - ACFD - ABHG + ABED
= prefix[x2+1][y2+1] - prefix[x2+1][y1] - prefix[x1][y2+1] + prefix[x1][y1]










*/
long long rsum(vector<vector<long long>>& prefix, int x1, int y1, int x2, int y2){
    return prefix[x2+1][y2+1] - prefix[x2+1][y1] - prefix[x1][y2+1] + prefix[x1][y1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> x_index, y_index;
    vector<vector<int>> pos(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> pos[i][0] >> pos[i][1];
        x_index[pos[i][0]] = 0;
        y_index[pos[i][1]] = 0;
    }
    int index = 0;
    for (std::map<int,int>::iterator it=x_index.begin(); it!=x_index.end(); ++it){
        it -> second = index;
        // cout << it->first << ":" << it -> second << ",";
        index++;
    }
    // cout << endl;
    index = 0;
    for (std::map<int,int>::iterator it=y_index.begin(); it!=y_index.end(); ++it){
        it -> second = index;
        // cout << it->first << ":" << it -> second << ",";
        index++;
    }
    // ofstream // ofs1("position-w1.txt");
    for(int i = 0; i < n; i++){
        pos[i][0] = x_index[pos[i][0]];
        pos[i][1] = y_index[pos[i][1]];
        // ofs1 << pos[i][0] << " " << pos[i][1] << endl;
    }
    // // cout << endl;
    // ofstream // ofs2("prefix-w1.txt");
    vector<vector<long long>> ps(n+1, vector<long long> (n+1));
    for(int i = 0; i < n; i++){
        ps[pos[i][0]+1][pos[i][1]+1] = 1;
    }
//    print(ps, n+1, n+1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ps[i+1][j+1] += ps[i][j+1] + ps[i+1][j] - ps[i][j];
            // ofs2 << ps[i+1][j+1] << " ";
        }
        // ofs2 << endl;
    }
    long long ans = 0;
    // ofstream // ofs("pasture-w1.txt");

//    print(ps, n+1, n+1);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int xi = pos[i][0], yi = pos[i][1], xj = pos[j][0], yj = pos[j][1];
//            int top = min(xi, xj);
//            int bottom = max(xi, xj);
//            int left = min(yi, yj);
//            int right = max(yi, yj);
            int left = min(xi, xj);
            int right = max(xi, xj);
            int top = min(yi, yj);
            int bottom = max(yi, yj);
            ans += rsum(ps, 0, top, left, bottom) * rsum(ps, right, top, n-1, bottom);
            // ofs << i << " " << j << " " <<  rsum(ps, 0, top, left, bottom) << " " << rsum(ps, right, top, n-1, bottom) << endl;

            // // cout << top << " " << bottom << " " << rsum(ps, 0, top, left, bottom) * rsum(ps, right, top, n-1, bottom) << endl;
        }
    }
    cout << ans+1 << endl;
}
/*
4
0 2
1 0
2 3
3 5
         x1     x2
A------B----------C
|      |          |
|      |          |
D------E----------F
|      |          | y1
|      |          |
|      |          | y2
G------H----------I
      left         right
A------B----------C-------------J
|      |          |             |
|      |          |             |
D------E----------F-------------K top
| 1    |          |             |
|   1  |          |  1    1     |
|      |          |    1        |
G------H----------I-------------L bottom
|      |          |             |
|      |          |             |
|      |          |             |
M------N----------O-------------P
0 0
0 3
3 0

4
0 2
1 0
2 3
3 5

x_index={0:0, 1:0, 2:0, 3:0}
y_index={0:0, 2:0, 3:0, 5:0}

x_index={0:0, 1:1, 2:2, 3:3}
y_index={0:0, 2:1, 3:2, 5:3}

0 0 1 0 0 0
1 0 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 1

 0 0

4
0 1, i = 0
1 0
2 2, j = 2
3 3
0 1 0 0
1 0 0 0
0 0 1 0
0 0 0 1

i = 0
j = 2

top = min(xi, xj)
bottom = max(xi, xj)
left = min(yi, yj)
right = max(yi, yj)

rsum(0, left, top, bottom) * rsum(right, n, top, bottom)

0 0 0 0 0
0 0 1 1 1
0 1 2 2 2
0 1 2 3 3
0 1 2 3 4
*/
