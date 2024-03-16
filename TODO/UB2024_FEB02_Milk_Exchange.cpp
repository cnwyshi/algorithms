#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m, ans = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> cap(n);
    for (int i = 0; i < n; i++) {
        cin >> cap[i];
        ans += cap[i];
    }
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'R' && s[(i + 1) % n] == 'L') {
            ll t = 0;
            for (int j = (i - 1) % n; s[j] == 'R'; j = (j -1 + n) % n) {
                t += cap[j];
            }
            ans -= min(t, m);
        }
        if (s[i] == 'L' && s[(i - 1 + n) % n] == 'R') {
            ll t = 0;
            for (int j = (i + 1) % n; s[j] == 'L'; j = (j + 1 + n) % n) {
                t += cap[j];
            }
            ans -= min(t, m);
        }
        // cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

/*
3 1
RRL
1 1 1

5 20
LLLLL
3 3 2 3 3

9 5
RRRLRRLLR
5 8 4 9 3 4 9 5 4

*/