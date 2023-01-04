#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t, n = 8;
    cin >> t;
    while (t -- > 0) {
        string s, ans = "B";
        for (int i = 0; i < n && ans == "B"; i ++) {
            cin >> s;
            bool red = true;
            for (int j = 0; j < n && red; j ++) {
                if (s[j] == 'B' || s[j] == '.') {
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