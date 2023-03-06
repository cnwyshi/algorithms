#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

// f(n) = f(n-1) + f(n-2)
// f(1) = f(2) = 1, f(3) = 2, f(4) = 3

int fib(int n) {
    if (n < 3) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

// [a, b, c]  -> [b, c, x]
int fib2(int n) {
    if (n < 3) {
        return 1;
    }
    int a = 1, b = 1, c = 0;
    for (int i = 0; i < n - 2; i ++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    for (int i = 1; i < 10; i ++) {
        cout << fib2(i) << endl;
    }
}