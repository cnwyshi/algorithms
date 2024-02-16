#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("/Users/genius/Downloads/sample-51.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        float f;
        cin >> f;
        l[i] = f * 100;
    }
    sort(l.begin(), l.end());
    //find biggest enough = find smallest unenough - 1
    int lo = 0, hi = 10000000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int num = 0;
        for (int v: l) {
            num += v / mid;
        }
//        cout << lo << " " << hi << " " << mid << " " << num << endl;
        if (num >= k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(2) << (lo - 1) / 100.0 << '\n';
}
/*
4 11
8.02 7.43 4.57 5.39
2.00

3 1
8 8 8

10000 10000
100000 ....

 100000
 L/ans*N= K
 ans = L*N/K
 ans <= 1e5*1e4/1= 1e9
*/










