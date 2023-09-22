#include <bits/stdc++.h>

using namespace std;

// https://duoblogger.github.io/assets/pdf/memonvyftw/guide-t-cp.pdf#page=156
/*
 * ax + by = gcd(a, b)
 * 30 * 1 + 12 * (-2) = 6
 * because, GCD(a, b) = GCD(b, a%b)
 * so, bx' + (a%b)y' = GCD(a, b)
 * meanwhile, a%b = a - [a/b] * b
 * so, bx' + (a-a/b*b)y' = GCD(a, b)
 * then, ay' + b(x' - [a/b]y') = GCD(a, b)
 *
*/
vector<int> ExtGCD(int a, int b) {
    if (b == 0) {
        // a * 1 + 0 * y = a
        return {1, 0, a};
    } else {
        vector<int> r = ExtGCD(b, a % b);
        int x = r[0], y = r[1], g = r[2];
        return {y, x - a / b * y, g};
    }
}

// https://oi-wiki.org/math/number-theory/inverse/
// https://oi-wiki.org/math/number-theory/linear-equation/
// https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-using-extended-euclidean-algorithm
/* xy = 1 (mod m)
 * 3y = 1 (mod 5), y = inv(3, 5) = 2
 *
 * ax = 1 (mod b), x = inv(a, b)
 * ax + by = 1
 *
*/
int inv(int a, int m) {
    return (ExtGCD(a, m)[0] % m + m) % m;
}

int main() {

    {
        vector<int> r = ExtGCD(10, 4);
        int a = r[0], b = r[1];
        cout << a << " " << b << endl;
    }
    {
        cout << inv(3, 10) << endl;
    }
    {
        cout << inv(3, 5) << endl;
    }

}

