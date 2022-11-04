#include <iostream>

using namespace std;

int main() {
    int n, t1 = 1, t2 = 1, t3 = 1, nextTerm = 3;
    cin >> n;
    if (n == 1) {
        cout << t1 << endl;
    }
    if (n == 2) {
        cout << t2 << endl;
    }
    if (n == 3) {
        cout << t3 << endl;
    }
    if (n == 4) {
        cout << 3 << endl;
    }
    for (int i = 4; i <= n; i++) {
        int x = nextTerm;
        t1 = t2;
        t2 = t3;
        t3 = nextTerm;
        nextTerm = t1 + t2 + t3;
        if (i == n - 1) {
            cout << nextTerm << endl;
        }
    }
    return 0;
}