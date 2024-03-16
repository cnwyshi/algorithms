#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        cout << (s.back() == '0' ? 'E' : 'B') << endl;
    }
    return 0;
}

/*
3
8
10
12
*/