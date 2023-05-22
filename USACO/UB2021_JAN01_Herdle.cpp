//
// Created by genius on 1/3/2023.
//

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
    vector<int> cc(27), cg(27);
    vector<string> s(3), t(3);
    int g = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
    for (int i = 0; i < 3; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s[i][j] == t[i][j]) {
                g++;
            } else {
                cc[s[i][j] - 'A']++;
                cg[t[i][j] - 'A']++;
            }
//            cout << i << " " << j << " " << y << endl;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
//        cout << cc[c-'A'] << cg[c-'A'] << endl;
        y += min(cc[c - 'A'], cg[c - 'A']);
    }
    cout << g << endl << y << endl;
    return 0;
}
/*
COW
SAY
MOO
WIN
THE
IOI

AAA
BBB
CCC
AYY
AAA
ZZZ
*/