#include <bits/stdc++.h>
using namespace std;

int fit(vector<int>& cow, int mx) {
    for (int th = mx; th >= 0; th --) {
        vector<int> copy(cow);
        int n = cow.size(), cost = 0, i = 0;
        for ( ; i + 1 < n; i ++) {
            if (copy[i] < th) {
                break;
            }
            int diff = copy[i] - th;
            copy[i] -= diff;
            copy[i + 1] -= diff;
            cost += diff + diff;
        }
        if (i == n - 1 && copy[n - 1] == th) {
            return cost;
        }
    }
    return -1;
}

int main() {
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        vector<int> cow(n);
        int mx = 0;
        for (int i = 0; i < n; i ++) {
            cin >> cow[i];
            mx = max(mx, cow[i]);
        }
        cout << fit(cow, mx) << endl;
    }
}

/*
SAMPLE INPUT:
5
3
8 10 5
6
4 6 4 4 6 4
3
0 1 0
2
1 2
3
10 9 9


SAMPLE OUTPUT:
14
16
-1
-1
-1

*/