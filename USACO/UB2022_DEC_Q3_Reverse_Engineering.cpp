#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    cout << t << endl;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << n << " " << m << endl;
        while (m--) {
            vector<int> nums(n);
            for (int i = 0; i < n; i++) {
                cin >> nums[i];
                cout << nums[i];
            }
            cout << " ";
            int out;
            cin >> out;
            cout << out << endl;
        }
    }
}
/*
4

1 3
0 0
0 0
1 1

2 4
00 0
01 1
10 1
11 1

1 2
0 1
0 0

2 4
00 0
01 1
10 1
11 0
 */