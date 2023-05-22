#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    // (-∞, x-1] + [x, ∞)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> desired(m);
    multiset<int> size;
    for (int i = 0; i < n; ++i) {
        cin >> desired[i];
    }
    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        size.insert(p);
    }
//    cout << endl;
//    for(int i = 0; i < m; i++){
//        cout << desired[i] << " ";
//    }
//    cout << endl;
    sort(desired.begin(), desired.end());
    int ans = 0;
    for (int i: desired) {
        multiset<int>::iterator it = size.lower_bound(i - k);
        if (it != size.end()) {
            if (abs(*it - i) <= k) {
                ans++;
                size.erase(*it);
            }
        }
    }
    cout << ans << '\n';
}
/*
4 3 5
60 45 80 60
30 60 75

2

3 2 5
10 20 30
25 16
*/