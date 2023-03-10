#include <bits/stdc++.h>
using namespace std;

// GCD(a, b) = GCD(b, a%b)
int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

// ax + by = gcd(a, b)
vector<int> ExtGCD(int a, int b) {
    if (b == 0) {
        return { 1, 0, a };
    } else {
        vector<int> r = ExtGCD(b, a % b);
        int x = r[0], y = r[1], g = r[2];
        return { y, x - a / b * y, g };
    }
}

int main() {
    cout << GCD(12, 18) << endl;
    vector<int> r = ExtGCD(30, 12);
    int x = r[0], y = r[1], g = r[2];
    cout << x << " " << y << " " << g << endl;
    r = ExtGCD(77, 33);
    int a = r[0], b = r[1];
    cout << a << " " << b << endl;
}