#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> cow(n), cane(m);
    for (int i = 0; i < n; i ++) {
        cin >> cow[i];
    }
    for (int j = 0; j < m; j ++) {
        cin >> cane[j];
    }
    for (int j = 0; j < m; j ++) {
        ll total = 0;
        for (int i = 0; i < n && total < cane[j]; i ++) {
            // ll eat = max(0LL, cow[i] - total);
            ll eat = max(0LL, min(cow[i], cane[j]) - total);
            cow[i] += eat;
            total += eat;
        }
    }
    for (int i = 0; i < n; i ++) {
        cout << cow[i] << endl;
    }
    return 0;
}

/*
SAMPLE INPUT:
3 2
3 2 5
6 1
SAMPLE OUTPUT:
7
2
7
*/