#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, P, sum = 0;
    cin >> N >> P;
    vector<vector<int>> p(P, vector<int>(2)), q(N, vector<int>(4));
    for (int i = 0; i < P; i ++) {
        cin >> p[i][0] >> p[i][1];
    }
    for (int i = 0; i < N; i ++) {
        cin >> q[i][0]>>q[i][1]>>q[i][2]>>q[i][3];
    }
    sort(p.begin(), p.end());
    for (int i = 1; i < P; i ++) {
        sum += abs(p[i-1][0] - p[i][0]) + abs(p[i-1][1] - p[i][1]);
    }
    int diff = p[1][1] - p[0][1];
    map<vector<int>, vector<int>> m;
    for (int i = 2; i < P; i += 2) {
        if (p[i][1] == p[i-1][1]) {

        }
    }


    return 0;
}

/*

 1 8
 0 0
 0 4
 1 4
 1 1
 2 1
 2 4
 3 4
 3 0
 1 3 3 0

 11


 [[0, 0], [0,2], [2,0], [2,2]]

输入样例：
5 4
0 0
2 0
2 2
0 2
0 0 0 2
0 2 1 0
2 1 0 2
1 0 1 2
1 2 1 0
输出样例：
2
3
3
4
4
*/