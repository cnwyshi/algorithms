#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <array>
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
    int t, n;
    cin >> t;
    while (t -- > 0) {
        string s, t;
        cin >> s >> t;
        int m = s.size(), n = t.size(), ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int c = 0, k = 0;
                for ( ; s[i + k] == t[j + k] && i + k < m && j + k < n; k ++) {
                    ans = max(ans, ++ c);
                }
            }
        }
        cout << m + n - ans - ans << endl;
    }
    return 0;
}

/*
5
a
a
abcd
bc
hello
codeforces
hello
helo
dhjakjsnasjhfksafasd
adjsnasjhfksvdafdser



*/