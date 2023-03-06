#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <array>

using namespace std;

int main() {
    int t, n = 8;
    cin >> t;
    while (t -- > 0) {
        vector<string> s(n);
        for (int i = 0; i < n; i ++) {
            cin >> s[i];
        }
        string ans = "B";
        for (int i = 0; i < n && ans == "B"; i ++) {
            bool red = true;
            for (int j = 0; j < n && red; j ++) {
                if (s[i][j] == 'B' || s[i][j] == '.') {
                    red = false;
                }
            }
            if (red) {
                ans = "R";
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
4


....B...
....B...
....B...
RRRRRRRR
....B...
....B...
....B...
....B...


RRRRRRRB
B......B
B......B
B......B
B......B
B......B
B......B
RRRRRRRB


RRRRRRBB
.B.B..BB
RRRRRRBB
.B.B..BB
.B.B..BB
RRRRRRBB
.B.B..BB
.B.B..BB


........
........
........
RRRRRRRR
........
........
........
........
*/