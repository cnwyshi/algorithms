#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int k, m, n, p, t, f;
    cin >> k >> m >> n;
    map<int, int> loc;
    for (int i = 0; i < k; i++) {
        cin >> p >> t;
        loc[p] = t;
    }
    for (int i = 0; i < m; i++) {
        cin >> f;

    }
    vector<vector<int>> v(k + m, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    for (int i = k; i < k + m; i++) {
        cin >> v[i][0];
        v[i][1] = -1;
    }
    sort(v.begin(), v.end());
    set<int> nhoj;
    for (int i = 0; i < k + m; i++) {

    }
    vector<int> range;
    for (int i = 0, s = 0; i <= k + m; i++) {
        if (i == k + m || v[i][1] == -1) {
            range.push_back(s);
            s = 0;
        } else {
            s += v[i][1];
        }
    }
    for (int r: range) {
        cout << r << " " << endl;
    }
}

/*

0     4       8  10    12 13
4     6       10  8    12 14
  2 3   5   7       11
                9
[4], [6], [10] [8], [12, 14]

6 5 2
0 4
4 6
8 10
10 8
12 12
13 14
2
3
5
7
11
*/