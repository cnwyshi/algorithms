#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, m, c;
        cin >> n >> m >> c;
        vector<int> cow(n);
        for (int i = 0; i < n; i ++) {
                cin >> cow[i];
        }
        sort(cow.begin(), cow.end());
        int lo = 0, hi = cow.back();
        while (lo < hi) {
                int mid = (lo + hi), t = 1, c = 0, f = cow.front();
                for (int v : cow) {
                        if (v - f <= mid && c < m) {
                                c ++;
                        } else {
                                c = 1;
                                f = v;
                                t ++;
                        }
                }
                if (t > m) {
                        lo ++;
                } else {
                        lo = mid;
                }
        }
        cout << lo << endl;

        return 0;

}

