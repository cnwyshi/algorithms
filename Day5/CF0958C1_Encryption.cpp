#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, p, ans = 0;
    cin >> n >> p;
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> v[i + 1];
        v[i + 1] += v[i];
    }
    for (int i = 1; i < n; i ++) {
        ans = max(ans, (int)(v[i] % p + (v[n] - v[i]) % p));
    }
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/958/C1
// https://blog.csdn.net/m0_55858144/article/details/119877301