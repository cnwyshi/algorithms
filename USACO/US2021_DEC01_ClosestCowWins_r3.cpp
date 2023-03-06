#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>


using namespace std;
using ll = long long;

int main() {
    int k, m, n, p = -1, s = 0;
    cin >> k >> m >> n;
    vector<vector<int>> patch(k + m, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> patch[i][0] >> patch[i][1];
    }
    for (int i = k; i < k + m; i++) {
        cin >> patch[i][0];
        patch[i][1] = -1;
    }

    priority_queue<ll> pq;
    sort(patch.begin(), patch.end());
    for (int i = 0; i < k + m; i++) {
        if (patch[i][1] == -1) {
            if (p == -1) {
                pq.push(s);
            } else {
                ll sum = 0, ans = 0;
                for (int j = p + 1, k = p + 1; j < i; j++) {
                    while (k < i && (patch[k][0] - patch[j][0]) * 2 < patch[i][0] - patch[p][0]) {
                        sum += patch[k++][1];
                    }
                    ans = max(ans, sum);
                    sum -= patch[j][1];
                }
                pq.push(ans);
                pq.push(s - ans);
            }
            p = i;
            s = 0;
        } else {
            s += patch[i][1];
        }
    }

    ll ans = 0;
    for (pq.push(s); n-- > 0; pq.pop()) {
        ans += pq.top();
    }
    cout << ans << endl;
}

/*

0     4       8  10    12 13
4     6       10  8    12 14
  2 3   5   7       11
                9
[4], [6], [10] [8], [12, 14]

6 5 2
0 4
4 6
8 10
10 8
12 12
13 14
2
3
5
7
11
*/