#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>


using namespace std;

// https://codeforces.com/problemset/problem/1670/B
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t --) {
        cin >> n;
        string s;
        cin >> s;
        vector<bool> special(26);
        cin >> k;
        for (int i = 0; i < k; i ++) {
            char c;
            cin >> c;
            special[c - 'a'] = true;
        }
        int ans = 0, c = 0, found = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (found) {
                ++ c;
            }
            ans = max(ans, c);
            int j = s[i] - 'a';
            if (special[j]) {
                c = 0;
                found = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
o

joobeel
2 o e
joobeel
11o11el
 s  s

jjjjjjjo
7654321s

jjjjjjoo
jjjjj  o
54321  s

oooo
---o

10
9
iloveslim
1 s
7
joobeel
2 o e
7
basiozi
2 s i
6
khater
1 r
7
abobeih
6 a b e h i o
5
zondl
5 a b c e f
6
shoman
2 a h
7
shetwey
2 h y
5
samez
1 m
6
mouraz
1 m


5
2
3
5
1
0
3
5
2
0

*/