#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double dt, c, du, p0, ans = 0;
    cin >> dt >> c >> du >> p0 >> n;
    cout << dt << c << du << p0 << n;
    vector<double> d(n + 1), p(n + 1);
    p[0] = p0;
    // vector<vector<double>> s(n, vector<double>(2));
    //  di, pi,
    for (int i = 1; i <= n; i ++) {
        // cin >> s[i][0] >> s[i][1];
        cin >> d[i] >> p[i];
        if (c * du < d[i] - d[i - 1]) {
            cout << "No solution";
            return 1;
        }
        ans += (d[i] - d[i - 1]) / p[i - 1];
    }
    if (c * du < dt - d[n]) {
        cout << "No solution";
        return 2;
    }
    ans += (dt - d[n]) / p[n];
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << ans << endl;
    // sort(s.begin(), s.end());
}

/**
样例输入：
275.6 11.9  27.4 2.8 2
102.0 29
220.0 2.2
样例输出：
  26.95
*/