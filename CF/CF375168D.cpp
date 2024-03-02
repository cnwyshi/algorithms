#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, n, k;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        string s;
        cin >> s;
        ll a = count(s.begin(), s.end(), 'A'), ans = 0;
        ll b = count(s.begin(), s.end(), 'B');
        ll c = count(s.begin(), s.end(), 'C');
        for (ll i = 1; i <= a && b > 0; i ++) {
            ans += max(0ll, c - k / i / b);
        }
        cout << ans << endl;
    }
    return 0;
}

/*
7
5 10
AAABC
5 1
AAABC
10 10
AAAAABBBCC
1 1000000000000
C
10 4
AABCCCCCCC
5 2
AAACC
31 3
AAAAAAAAAABBBBBBBBBBBBCCCCCCCCC
*/
