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

// https://codeforces.com/problemset/problem/1373/A
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


#define ll              long long
#define ull             unsigned long long
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;

int main() {
    fastread();
    int t;
    ll a, b, c, f, s;
    cin >> t;
    while (t--) {
        f = -1, s = -1;
        cin >> a >> b >> c;

        if (a < c) {
            f = 1;
        }
//        if (a + a < c) {
//            f = 2;
//        }
        if (a * b > c) {
            s = b;
        }
        cout << f << " " << s << endl;
    }

    return 0;
}

/*
4
5 10 4
4 5 20
2 2 3
1000000000 1000000000 1000000000



*/