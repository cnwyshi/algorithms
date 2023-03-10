#include <bits/stdc++.h>
using namespace std;

// GCD(a, b) = GCD(b, a%b)
int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

// ax + by = gcd(a, b)
tuple<int, int, int> ExtGCD(int a, int b) {
    if (b == 0) {
        return { 1, 0, a };
    } else {
        int x, y, g;
        tie(x, y, g) = ExtGCD(b, a % b);
        return { y, x - (a/b) * y, g };
    }
}

int main() {
    cout << GCD(12, 18) << endl;
    int x, y, g;
    tie(x, y, g) = ExtGCD(30, 12);
    cout << x << " " << y << " " << g << endl;
    int a, b;
    tie(a, b, g) = ExtGCD(77, 33);
    cout << a << " " << b << endl;
}