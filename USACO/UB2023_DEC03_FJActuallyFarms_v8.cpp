#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<ll>> plant(n, vector<ll>(3));
        for (int i = 0; i < n; i++) {
            cin >> plant[i][1];
        }
        for (int i = 0; i < n; i++) {
            cin >> plant[i][2];
        }
        for (int i = 0; i < n; i++) {
            cin >> plant[i][0];
            plant[i][0] = n - plant[i][0];
        }
        sort(plant.begin(), plant.end());
        ll day = 0;
        for (int i = 0; i + 1 < n; i++) {
            ll dh = plant[i][1] - plant[i + 1][1], da = plant[i + 1][2] - plant[i][2];
            if (dh > 0 && da > 0) {
                day = max(day, dh / da + 1);
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (plant[i][1] + plant[i][2] * day >= plant[i + 1][1] + plant[i + 1][2] * day) {
                day = -1;
                break;
            }
        }
        cout << day << "\n";
    }
    return 0;
}

/*
1
2
7 3
8 10
1 0

1
3
3 8 5
3 1 3
2 1 0

2
5
7 4 1 10 12
3 4 5 2 1
2 1 0 3 4
5
4 10 12 7 1
3 1 1 4 5
2 4 3 1 0
*/