#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t, n = 8;
    cin >> t;
    while (t -- > 0) {
        vector<set<int>> row(n), col(n);
        for (int i = 0; i < n; i ++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j ++) {
                row[i].insert(s[j]);
                col[j].insert(s[j]);
            }
        }
        for (int i = 0; i < n; i ++) {
            if (row[i].size() == 1 && row[i].find('.') == row[i].end()) {
                cout << (char)*row[i].begin() << endl;
                break;
            } else if (col[i].size() == 1 && col[i].find('.') == col[i].end()) {
                cout << (char)*col[i].begin() << endl;
                break;
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