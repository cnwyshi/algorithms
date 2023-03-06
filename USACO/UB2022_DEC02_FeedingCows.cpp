#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>


using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t -- > 0) {
        cin >> n >> k;
        string cows;
        cin >> cows;
        vector<int> g, h;
        for (int i = 0; i < n; i ++) {
            if (cows[i] == 'G') {
                g.push_back(i);
            } else {
                h.push_back(i);
            }
        }

        int count = 0, j = INT_MIN / 2;
        string ans(n, '.');
        for (int i = 0; i < g.size(); i ++) {
            if (abs(j - g[i]) > k) {
                j = min(g[i] + k, n - 1);
                ans[j] = 'G';
                count ++;
            }
        }
        j = INT_MAX / 2;
        for (int i = h.size() - 1; i >= 0; i --) {
            if (abs(j - h[i]) > k) {
                j = max(h[i] - k, 0);
                for ( ; j < n && ans[j] == 'G'; j ++) {
                }
                ans[j] = 'H';
                count ++;
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