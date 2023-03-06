#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t -- > 0) {
        cin >> n >> k;
        string s, ans(n, '.');
        cin >> s;
        int count = 0;
        for (char c : { 'G', 'H'}) {
            for (int i = 0, last = -k - 1; i < n; i ++) {
                if (s[i] == c && abs(i - last) > k) {
                    last = min(i + k, n - 1);
                    for ( ; ans[last] != '.'; last --) {
                    }
                    ans[last] = c;
                    count ++;
                }
            }
        }
        cout << count << endl << ans << endl;
    }
    return 0;
}

/*
5 1
GHHGG
 G  G

6
5 0
GHHGG
5 1
GHHGG
5 2
GHHGG
5 3
GHHGG
5 4
GHHGG
2 1
GH




5 0
GHHGG
->5
GHHGG

5 1
GHHGG
 ->3
.GH.G

5 2
GHHGG
 ->2
..GH.

5 3
GHHGG
->2
...GH

5 4
GHHGG
->2
...HG

2 1
GH
-> 2
HG
*/