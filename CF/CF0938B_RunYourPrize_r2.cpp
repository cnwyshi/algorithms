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
    int n, a, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = max(ans, min(a - 1, 1000000 - a));
    }
    cout << ans << endl;
    return 0;
}