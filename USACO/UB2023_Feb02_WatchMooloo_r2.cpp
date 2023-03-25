#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> d(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    ll ans = 1LL + K;;
    for (int i = 1; i < N; i++) {
        ans += min(d[i] - d[i - 1], 1LL + K);
    }
    cout << ans << endl;
}