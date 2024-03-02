#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b, x;
    cin >> t;
    while (t-- > 0) {
        cin >> a >> b >> x;
        cout << ((a-x) % (a-b) == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
2a - b = x
a - b = x - a
2a - (2a - b) = b
2b - (2a - b) = 3b - 2a
2(2a - b) - a = 3a - 2b
2(2a - b) - b = 4a - 3b


|---


1 5 9
*/
