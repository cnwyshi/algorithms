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
    while (t-- > 0) {
        string s;
        int n, m;
        cin >> n >> m;
        vector<string> b(m);
        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i] >> v[i];
        }

        set<int> rows;
        while (true) {
            bool change = false;
            for (int j = 0; j < n; j++) {
                vector<set<int>> count(2);
                for (int i = 0; i < m; i++) {
                    if (rows.find(i) == rows.end()) {
                        count[b[i][j] - '0'].insert(v[i]);
                    }
                }
                for (int i = 0; i < m; i++) {
                    if (count[b[i][j] - '0'].size() == 1) {
                        rows.insert(i);
                        change = true;
                    }
                }
            }
            if (!change || rows.size() == m) {
                break;
            }
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