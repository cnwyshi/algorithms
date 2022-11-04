#include <iostream>
using namespace std;

int fib(int n) {
    return n <= 3 ? 1 : fib(n-3)+fib(n-2)+fib(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}