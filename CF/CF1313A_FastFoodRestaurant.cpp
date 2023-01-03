#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int x[7][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
int main() {
    int t, i, ans;
    cin >> t;
    while (t --) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        for (i = 0, ans = 0; i < 7; i ++) {
            if (v[0] >= x[i][0] && v[1] >= x[i][1] && v[2] >= x[i][2]) {
                v[0] -= x[i][0], v[1] -= x[i][1], v[2] -= x[i][2];
                ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
7
1 2 1
0 0 0
9 1 7
2 2 3
2 3 2
3 2 2
4 4 4

3 2 2
    1
  1
1
  1 1



2 2 3
    1
  1
1
  1 1
1   1

*/