#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t -- > 0) {
        string s;
        cin >> s;
        if (s.find("MOO") != s.npos) {
            cout << s.size() - 3 << endl;
        } else if (s.find("MOM") != s.npos || s.find("OOO")!= s.npos) {
            cout << s.size() - 2 << endl;
        } else if (s.find("OOM")!= s.npos) {
            cout << s.size() - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

/*
SAMPLE INPUT:
3
MOMMOM
MMO
MOO
SAMPLE OUTPUT:
4
-1
0
*/