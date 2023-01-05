#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n), v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = n - 1, j = n - 1; i >= 0; ) {
        if (v[b[j]]) {
            j --;
        } else if (a[i] != b[j]) {
            v[a[i]] = 1;
            i --;
            ans ++;
        } else if (a[i] == b[j]) {
            i --;
            j --;
        }
    }
    cout << ans << endl;
}

/*
5
5 1 3 2 4
4 5 2 1 3

5
1 2 3 4 5
1 2 3 4 5
*/
