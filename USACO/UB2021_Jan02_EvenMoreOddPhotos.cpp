#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    int O = 0, E = 0, n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            E++;
        } else {
            O++;
        }
    }
    while (O > E) {
        O = O - 2;
        E++;
    }
    if (E > O + 1) {
        E = O + 1;
    }
    cout << E + O << "\n";
}