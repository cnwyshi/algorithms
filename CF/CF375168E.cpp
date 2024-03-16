#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, q, v;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> tree(n);
        while (q--) {
            cin >> v;
            tree[--v] ++;
        }
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += tree[i] % 2;
            for (int j = i * 2 + 1; j <= i * 2 + 2; j ++) {
                if (j < n) {
                    tree[j] = (tree[j] + tree[i]) % 2;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
3
5 5
1 4 2 3 3
2 4
1 2 2 2
3 2
2 3
*/