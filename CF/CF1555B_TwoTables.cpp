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

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int rw, rh, x1, y1, x2, y2, tw, th;
        cin >> rw >> rh >> x1 >> y1 >> x2 >> y2 >> tw >> th;
        int w = x2 - x1, h = y2 - y1, ans = -1;
        if (w + tw <= rw || h + th <= rh) {
            ans = max(rw, rh);
            int left = x1, right = rw - x2, bottom = y1, top = rh - y2;
            if (w + tw <= rw) {     // horizental
                ans = min(ans, max(0, min(tw - left, tw - right)));
            }
            if (h + th <= rh) {     // vertical
                ans = min(ans, max(0, min(th - top, th - bottom)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
