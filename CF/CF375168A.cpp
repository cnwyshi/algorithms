#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0, n = 0;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        int mi = INT_MAX, v = 0;
        for (int i = 0; i < n; i ++) {
            cin >> v;
            mi = min(mi, v);
        }
        cout << mi << endl;
    }
    return 0;
}

/*
inputCopy
4
4
1 2 3 4
1
10
3
1 1 1
5
4 6 3 2 5
outputCopy
1
10
1
2
*/
