#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <array>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t -- > 0) {
        string s;
        int n, m, r;
        cin >> n >> m;
        vector<string> b(m);
        vector<int> v(m);
        for (int i = 0; i < m; i ++) {
            cin >> b[i] >> v[i];
        }

        set<int> rows, cols;
        while (true) {
            int last = rows.size();
            vector<vector<int>> count(n, vector<int>(2));
            for (int i = 0; i < m; i ++) {
                if (rows.find(i) == rows.end()) {
                    for (int j = 0; j < n; j ++) {
                        if (cols.find(j) == cols.end()) {
                            count[j][b[i][j] - '0'] |= 1 << v[i];
                        }
                    }
                }
            }

            int i = 0, found = 0;
            for ( ; i < m && !found; i ++) {
                if (rows.find(i) == rows.end()) {
                    for (int j = 0; j < n && !found; j++) {
                        int c = count[j][b[i][j] - '0'];
                        if (c == 1 || c == 2) {
                            rows.insert(i);
                            cols.insert(j);
                        }
                    }
                }
            }
            if (rows.size() == last || rows.size() == m) {
                break;
            }
            last = rows.size();
        }
        cout << (rows.size() == m ? "OK" : "LIE") << endl;
    }
    return 0;
}

/*
4

1 3
0 0
0 0
1 1

2 4
00 0
01 1
10 1
11 1

1 2
0 1
0 0

2 4
00 0
01 1
10 1
11 0

---
2 4
00 0
01 1
10 1
11 1

if (b[1] == 1) return 1;
else if (b[0] == 0) return 0;
else return 1;
*/