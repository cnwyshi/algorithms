#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i = 0;
    cin >> n;
    vector<int> ans(n);
    for (int d = n - 1; abs(d) > 0; ) {
        ans[i] = d;
        i += d;     // 5 -> -4,  -4 -> 3
        d = d > 0 ? 1 - d : -1 - d;
    }
    ans[i] = n;
    cout << n - 1 << endl << 1 << endl;
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}

/*
4
3
1
3 -1 4 -2

5
4
1
4 2 5 1 -3
*/
