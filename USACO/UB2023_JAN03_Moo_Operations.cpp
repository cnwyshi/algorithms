#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        if (n < 3) {
            cout << -1 << endl;
        } else if (s.find("MOO") != s.npos) {
            cout << n - 3 << endl;
        } else if (s.find("MOM") != s.npos || s.find("OOO") != s.npos) {
            cout << n - 2 << endl;
        } else if (s.find("OOM") != s.npos) {
            cout << n - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
/*
3
MOMMOM
MMO
MOO

s.size() < 3, -1
*/