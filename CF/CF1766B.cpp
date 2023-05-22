#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <array>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t-- > 0) {
        string s;
        cin >> n;
        cin >> s;
        bool found = false;
        set<string> visited;
        for (int i = 2; i < n && !found; i++) {
            if (visited.find(s.substr(i - 1, 2)) != visited.end()) {
                found = true;
            }
            visited.insert(s.substr(i - 2, 2));
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
6
10
codeforces
8
labacaba
5
uohhh
16
isthissuffixtree
1
x
4
momo


*/