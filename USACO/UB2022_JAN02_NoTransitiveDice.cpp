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
using vi = vector<int>;

bool beat(vi& a, vi& b) {
    int x = 0, y = 0;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            if (a[i] > b[j]) {
                x ++;
            } else if (a[i] < b[j]) {
                y ++;
            }
        }
    }
    return x > y;
}

bool non_transitive(vi& a, vi& b, vi& c) {
    return beat(a, b) && beat(b, c) && beat(c, a)
        || beat(b, a) && beat(a, c) && beat(c, b);
}

bool solve(vi& a, vi& b) {
    for (int i = 1; i <= 10; i ++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int l = 1; l <= 10; l++) {
                    vi c = {i, j, k, l};
                    if (non_transitive(a, b, c)) {
                        return true;
                    }

                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t -- > 0) {
        vector<int> a(4), b(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3];
        cout << (solve(a, b) ? "yes" : "no") << endl;
    }
}

/*
3
4 5 6 7 2 4 5 10
2 2 2 2 1 1 1 1
1 1 1 1 2 2 2 2
*/