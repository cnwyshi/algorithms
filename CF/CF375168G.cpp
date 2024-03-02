#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, a, b, x, c, s;
    cin >> t;
    while (t --) {
        cin >> a >> b >> x;
        ll d = abs(a - b);
        if ((x-a) % d) {
            cout << "-1" << endl;
            continue;
        } else if (x == a || x == b) {
            cout << 0 << endl;
            continue;
        }
        if (a > b) {
            swap(a, b);
        }
        if (x < a) {
            c = (a - x) / d;
            s = b;
            d = -d;
        } else {
            c = (x - b) / d;
            s = a;
        }
        vector<vector<ll>> step;
        for (++c; c > 1; c = (c + 1) / 2) {
            if (c & 1) {
                step.push_back({ 1, (c + 1) / 2 });
            } else {
                step.push_back({0, c / 2});
            }
        }
        reverse(step.begin(), step.end());
        cout << step.size() << endl;
        for (vector<ll>& v : step) {
            cout << (s + v[0] * d) << " " << (s + v[1] * d) << endl;
        }
        cout << endl;
    }
    return 0;
}

/*
4
1 5 9
13 9 1
25 92 1
1 100 100

*/

