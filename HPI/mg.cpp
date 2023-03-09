#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double dt, c, du, p0;
    cin >> dt >> c >> du >> p0 >> n;
    vector<double> d(n + 2), p(n + 2);
    p[0] = p0;
    d[n + 1] = dt;
    for (int i = 1; i < n + 2; i++) {
        if (i <= n) {
            cin >> d[i] >> p[i];
        }
        if (c * du < d[i] - d[i - 1]) {
            cout << "No solution";
            return 0;
        }
    }

    for (int i = 0; i <= n; i++) {
        int j = i + 1;

        double di = s[i][0] - s[i - 1][0], ci = di / du;

        if (i < n) {
            if (s[i - 1][1] > s[i][1]) {
                ans -= pl * (c - ci);
                ans += s[i][1] * c;
                pl = s[i][1];
            }
        } else {

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