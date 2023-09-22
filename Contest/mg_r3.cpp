#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double dt, c, du, p0, ans = 0;
    cin >> dt >> c >> du >> p0 >> n;
    vector<vector<double>> s(n + 2, vector<double>(2));
    s[0][1] = p0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
    }
    s[n + 1][0] = dt;

    sort(s.begin(), s.end());
    for (int i = 1; i <= n + 1; i++) {
        if (c * du < s[i][0] - s[i - 1][0]) {
            cout << "No solution";
            return 1;
        }
        ans += (s[i][0] - s[i - 1][0]) / du * s[i - 1][1];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << ans << endl;
}

/**
样例输入：
275.6 11.9  27.4 2.8 2
102.0 2.8
220.0 2.2
样例输出：
  26.95
*/