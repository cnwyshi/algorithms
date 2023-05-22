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
int n;
string s;

bool ok(int len) {
    set<string> x;
    for (int i = 0; i <= n - len; i++) {
        if (x.count(s.substr(i, len)) > 0) {
            return true;
        }
        x.insert(s.substr(i, len));
    }
    return false;
}

int main() {
    cin >> n >> s;
    int ans = 1;
    while (ok(ans)) {
        ans++;
    }
    cout << ans << endl;
}