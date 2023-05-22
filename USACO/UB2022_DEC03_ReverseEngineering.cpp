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
        int n, m, r;
        cin >> n >> m;
        vector<string> b(m);
        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i] >> v[i];
        }

        set<int> correct;
        while (true) {
            vector<vector<int>> count(n, vector<int>(2));
            int last = correct.size();
            for (int i = 0; i < m; i++) {
                if (correct.find(i) == correct.end()) {
                    for (int j = 0; j < n; j++) {
                        count[j][b[i][j] - '0'] |= 1 << v[i];
                    }
                }
            }

            vector<vector<bool>> match(n, vector<bool>(2));
            for (int j = 0; j < n; j++) {
                if (count[j][0] == 1 || count[j][0] == 10) {
                    match[j][0] = true;
                } else if (count[j][1] == 1 || count[j][1] == 10) {
                    match[j][1] = true;
                }
            }

            for (int i = 0; i < m; i++) {
                if (correct.find(i) == correct.end()) {
                    bool found = false;
                    for (int j = 0; j < n; j++) {
                        if (match[j][b[i][j] - '0']) {
                            correct.insert(i);
                        }
                    }
                }
            }

            if (correct.size() == last) {
                break;
            } else {
                last = correct.size();
            }
        }
        cout << (correct.size() == n ? "OK" : "LIE") << endl;
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