#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <array>
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
    int t, n;
    cin >> t;
    while (t -- > 0) {
        cin >> n;
        string s;
        cin >> s;
        int i = s.find('1'), j = n - 1 - s.rfind('1');
        if (i == s.npos) {
            cout << n << endl;
        } else {
            cout << n + n - min(i, j) * 2 << endl;
        }
    }
    return 0;
}

/*
00100

101



4
5
00100
8
00000000
5
11111
3
110



*/