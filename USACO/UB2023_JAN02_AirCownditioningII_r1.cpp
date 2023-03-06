#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    vector<int> s(n), t(n), c(n), a(m), b(m), p(m), mo(m);
    for (int i = 0; i < n; i ++) {
        cin >> s[i] >> t[i] >> c[i];
    }
    for (int i = 0; i < m; i ++) {
        cin >> a[i] >> b[i] >> p[i] >> mo[i];
    }
    for (int used = 0; used < 1 << m; used ++) {
        int cost = 0, valid = 1;
        vector<int> cool(101);
        for (int i = 0; i < m; i ++) {
            if ((used & (1 << i)) != 0) {
                cost += mo[i];
                for (int j = a[i]; j <= b[i]; j ++) {
                    cool[j] += p[i];
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = s[i]; j <= t[i]; j ++) {
                valid &= c[i] <= cool[j];
            }
        }
        ans = valid ? min(ans, cost) : ans;
    }
    cout << ans <<endl;
}

/*
2 4
1 5 2
7 9 3
2 9 2 3
1 6 2 8
1 2 4 2
6 9 1 5

SAMPLE OUTPUT:
10

The first line of input contains N and M.
The next N lines describe cows. The ith of these lines contains si, ti, and ci.
The next M lines describe air conditioners. The ith of these lines contains ai, bi, pi, and mi.
For every input other than the sample, you can assume that M=10.
*/