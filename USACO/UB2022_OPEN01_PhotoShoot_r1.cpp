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
    int n, ans = 0, last = '.';
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            if (s[i] != last) {
                ans++;
            }
            last = s[i];
        }
    }
    if (last == 'H') {
        ans--;
    }
    cout << ans << endl;
    return 0;
}

/*
14
GGGHGHHGHHHGHG
*/