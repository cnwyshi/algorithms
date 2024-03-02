#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void print(vector<ll>& nums) {
    for (int v : nums) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, n, m;
    cin >> q;
    while (q --) {
        cin >> n >> m;
        vector<ll> diff(n);
        vector<vector<int>> p(m, vector<int>(2));
        for (int i = 0; i < m; i ++) {
            cin >> p[i][0];
            p[i][1] = i + 1;
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < m; i ++) {
            int j = (p[(i + 1) % m][0] - p[i][0] + n) % n;
            int d = p[(i + 1) % m][1];
            diff[0] += d;
            diff[j] -= d;
            print(diff);
        }

        ll slope = 0, ans = 0;
        for (int i = 0; i < n; i ++) {
            slope += diff[i];
            ans += slope;
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
p = [[1, 1], [2, 2]]
i = 0, j = 1, d = 2, diff = [2, -2, 0, 0, 0]
i = 1, j = 4, d = 1, diff = [3, -2, 0, 0, -1]

 i = 0, s = 3, ans = 3
 i = 1, s = 1, ans = 4
 i = 2, s = 1, ans = 5
 i = 3, s = 1, ans = 6
 i = 4, s = 0, ans = 6

0 0 0 0 0
1 2
1 1 2
1 1 1 2
1 1 1 1 2
2 1 1 1 1

p = [[9, 1], [2, 2], [8, 3], [4, 4], [15, 5]]
p = [[2, 2], [4, 4], [8, 3], [9, 1], [15, 5]]

 i = 0, j = 2, d = 4, diff = 4 0 -4 0 0 0 0 0 0 0 0 0 0 0 0
 i = 1, j = 4, d = 3, diff = 7 0 -4 0 -3 0 0 0 0 0 0 0 0 0 0
 i = 2, j = 1, d = 1, diff = 8 -1 -4 0 -3 0 0 0 0 0 0 0 0 0 0
 i = 3, j = 6, d = 5, diff = 13 -1 -4 0 -3 0 -5 0 0 0 0 0 0 0 0
 i = 4, j = 2, d = 2, diff = 15 -1 -6 0 -3 0 -5 0 0 0 0 0 0 0 0

[0, ]
3
5 2
1 2
2 2
1 2
15 5
9 2 8 4 15




*/
