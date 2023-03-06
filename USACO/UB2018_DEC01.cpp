#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<int> c(3), m(3);
    freopen("mixmilk.in", "r", stdin);
    cin >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];
    for (int i = 0; i < 100; i ++) {
        int x = i % 3, y = (i + 1) % 3, t = min(m[x], c[y] - m[y]);
        m[x] -= t;
        m[y] += t;
    }
    freopen("mixmilk.out", "w", stdout);
    cout << m[0] << endl << m[1] << endl << m[2] << endl;
    return 0;
}

/*
10 3
11 4
12 5

*/