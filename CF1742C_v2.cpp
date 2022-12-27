#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t, n = 8;
    cin >> t;
    while (t -- > 0) {
        bool found = false;
        vector<string> col(n, string(n, '.'));
        for (int i = 0; i < n && !found; i ++) {
            string s;
            cin >> s;
            if (s == "RRRRRRRR" || s == "BBBBBBBB") {
                cout << s[0] << endl;
                found = true;
            }
            for (int j = 0; j < n; j ++) {
                col[j][i] = s[j];
            }
        }
        for (int j = 0; j < n && !found; j ++) {
            if (col[j] == "RRRRRRRR" || col[j] == "BBBBBBBB") {
                cout << col[j][0] << endl;
                found = true;
            }
        }
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