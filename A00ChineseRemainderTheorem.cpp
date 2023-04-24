#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
 *
 * xa = 1 (mod b)
 * xa + by = 1
 *
*/
int inv(int x, int m) {
    return (ExtGCD(x, m)[0] % m + m) % m;
}

// https://oi-wiki.org/math/number-theory/crt/
// https://cp-algorithms.com/algebra/chinese-remainder-theorem.html#direct-construction
/*
 * x = r1 (mod m1)
 * x = r2 (mod m2)
 * x = r3 (mod m3)
 * M = m1*m2*...*mn
 * for each i
 *      m = M / mi,
 *      ans += ri * m * inv(m, mi)
*/
ll CRT(vector<ll> &rv, vector<ll> &mv) {
    ll n = rv.size(), M = 1, ans = 0;
    for (ll v: mv) {
        M *= v;
    }
    for (int i = 0; i < n; i++) {
        ll m = M / mv[i];
        ans = (ans + rv[i] * m * inv(m, mv[i]) % M) % M;
    }
    return (ans % M + M) % M;
}

int main() {
    // x = 2 (mod 3)
    // x = 3 (mod 5)
    // x = 2 (mod 7)
    vector<ll> r = {2, 3, 2};
    vector<ll> m = {3, 5, 7};
    cout << CRT(r, m) << endl;
}

