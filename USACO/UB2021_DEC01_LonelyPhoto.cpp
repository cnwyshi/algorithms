#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i ++) {
        ll x = 0, y = 0;
        for (int j = i - 1; j >= 0 && s[j] != s[i]; j --, x ++) {
        }
        for (int j = i + 1; j < n && s[j] != s[i]; j ++, y ++) {
        }
        ans += x * y + max(0LL, x - 1) + max(0LL, y - 1);
    }
    cout << ans << endl;
}

/*
5
GHGHG
*/