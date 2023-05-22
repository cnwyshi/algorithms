#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> diamonds(n);
    for (int i = 0; i < n; ++i) {
        cin >> diamonds[i];
    }
    vector<int> right(n), m(n);
    sort(diamonds.begin(), diamonds.end());
    for (int i = 0; i < n; i++) {
        int crt = diamonds[i];
        for (int j = i; j < n; j++) {
            if (diamonds[j] - crt <= k) {
                right[i]++;
            } else {
                break;
            }
        }
    }
    m[n - 1] = right[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        m[i] = max(m[i + 1], right[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, right[i] + m[i + right[i]]);
    }
    cout << ans << endl;
    return 0;
}
/*
7 3
10
5
1
12
9
5
14

      1 5 5 9 10 12 14
left  1 1 2 1 2  3  2
right 1 2 1 3 2  2  1
      2 3 3 4 4  5  3

i     0 1 2  3 4 5  6
      1 5 5 9 10 12 14
first  1 2 1 3 2  2  1
        -
sec   3 3 3 3 2  2  1
            -

*/