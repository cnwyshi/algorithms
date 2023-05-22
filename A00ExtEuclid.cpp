#include <bits/stdc++.h>

using namespace std;

// GCD(a, b) = GCD(b, a%b)
int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

// ax + by = gcd(a, b)
vector<int> ExtGCD(int a, int b) {
    if (b == 0) {
        return {1, 0, a};
    } else {
        vector<int> r = ExtGCD(b, a % b);
        int x = r[0], y = r[1], g = r[2];
        return {y, x - a / b * y, g};
    }
}

int main() {
//    cout << GCD(12, 18) << endl;
//    vector<int> r = ExtGCD(30, 12);
//    int x = r[0], y = r[1], g = r[2];
//    cout << x << " " << y << " " << g << endl;
    {

        vector<int> r = ExtGCD(77, 33);
        int a = r[0], b = r[1];
        cout << a << " " << b << endl;
    }
    {

        vector<int> r = ExtGCD(10, 4);
        int a = r[0], b = r[1];
        cout << a << " " << b << endl;
    }
    {

        vector<int> r = ExtGCD(27, 22);
        int a = r[0], b = r[1];
        cout << a << " " << b << endl;
    }
    {

        vector<int> r = ExtGCD(5, 16);
        int a = r[0], b = r[1];
        cout << a << " " << b << endl;
    }


}

/*
Vincent: 10 4
GCD(10, 4) = GCD(4, 10%4) = GCD(4, 2) = GCD(2, 4%2) = GCD(2, 0) = 2
10x + 4y = minValue = GCD(10, 4)
Solution: Impossible
Alvin: 27 22
William: 16 5
Solution: 1 -3

 */