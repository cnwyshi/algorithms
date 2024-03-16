#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, q, v, s;
    cin >> n >> q;
    vector<int> c(n), t(n), diff(n);
    for (int& v : c) {
        cin >> v;
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        diff[i] = c[i] - t[i];
    }
    std::sort(diff.rbegin(), diff.rend());
    while (q --) {
        cin >> v >> s;
        cout << (diff[v - 1] > s ? "YES" : "NO") << endl;
        if (diff[v] < s) {}
    }
    return 0;
}

/*
5 5
3 5 7 9 12
4 2 3 3 8
1 5
1 6
3 3
4 2
5 1

v = 1, s = 5
t + s = [9, 7, 8, 8, 13]
    c = [3, 5, 7, 9, 12]

n = 5, q = 5
c = [3, 5, 7, 9, 12]
t = [4, 2, 3, 3, 9]
c = [-1, 3, 4, 6, 3]
df = [6, 4, 3, 3, -1]
v = 1, s = 5, df[1-1] > 5
v = 1, s = 6, df[1-1] <= 6
*/